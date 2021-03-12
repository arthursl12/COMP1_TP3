%{
    #include <stdio.h>    
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>
    #include <ctype.h>
    #include "tab.h"
    #include "lists.h"
    #include "codinterm.h"

    #include "aux.h"


    #define YYDEBUG 0          /* Se ligado, imprime mais informações */


    /* Forward declaration de funções do parser */
    void yyerror (char *s);
    void typeerror();
    void typeerror_msg(char* msg);
    int yylex();
    void tempTipo(int* tipo1, int* tipo2, intmdt_addr_t* s1, intmdt_addr_t* s3);
    bool isNumber(int tipo);
    bool isNumToReal(char* funct);
    
    /* Globals da Tabela de Símbolos */
    extern int escopo[10];
    extern int nivel;      /* nível atual */
    extern int L;          /* índice do último elemento da tabela */
    extern int Raiz;   

    /* Funções Auxiliares da Tabela de Símbolos */
    void installIdentList(char* type, list_head_t* list);
    int novoVal = 1;       /* Global para testar o updateVal */
    void updateVal(char* id, char* value);
    int q = 0;              /* Tamanho do ident_list */
    char* id_list[20];      /* Lista de identificadores numa declaração */

    /* Lista de Quádruplas geradas */
    intmdt_code_t *intermediate_code;
%}

%code requires{
    #include "codinterm.h"
    #include <stdbool.h>
}

%union {
    int integer; 
    float real; 
    int boolean; 
    char character; 
    char* string; 
    char* lexeme_str; 
    intmdt_addr_t* intmdt_addr;


    /* Tipos de Não-terminais */
    struct stmt_t{
        list_head_t* next;
    } stmt_t;
    struct loop_aux_stmt_t{
        list_head_t* loop_main_next_list;
        list_head_t* next;
    } loop_aux_stmt_t;
    struct stmt_pref_t{
        bool hasPrefix;
        list_head_t* falselist;
        list_head_t* truelist;
    } stmt_pref_t;
    struct stmt_suff_t{
        bool hasSuffix;
        list_head_t* truelist;
        list_head_t* falselist;
    } stmt_suff_t;
    struct expr { 
        int type; 
        union value value;
    } expr;
    struct expr_lst_t { 
        list_head_t* list;
        int qtd_terms;
    } expr_lst_t;
    struct ident_list { 
        list_head_t* list;
        int qtd_terms;
    } ident_list_t;

}         /* Yacc definitions */

/* Tokens */
/* Tokens operações */
%token <lexeme_str> RELOP
%token <lexeme_str> MULOP AND 
%token <lexeme_str> ADDOP OR
%token MINUS            // -
// Obs.: o analisador sintático decide se é a subtração ou o menos unário

%token NOT
%token ASSIGN
%token <integer> INT_CONSTANT
%token <real> REAL_CONSTANT
%token <boolean> TRUE_CST FALSE_CST
%token <string> IDENTIFIER
%token <string> IDENTIFIER_F       // Identificador de funções-padrão
%token <character> CHAR_CONSTANT

/* Tokens de Palavras Reservadas */
%token PROGRAM
%token <string> INTEGER REAL BOOLEAN CHAR
%token BEGIN_STMT END
%token IF THEN ELSE
%token DO WHILE
%token UNTIL
%token READ WRITE GOTO

/* Símbolo de partida */
%start program

/* Associatividade e Precedência */
%right AND OR
%nonassoc RELOP
%left ADDOP MINUS 
%left MULOP
%right NOT
%nonassoc THEN
%nonassoc ELSE

/* Tipos de alguns símbolos Não-terminais */
%type <string> type decl label
%type <ident_list_t> ident_list
%type <intmdt_addr> boolean_constant constant factor factor_a expr simple_expr term
%type <intmdt_addr> function_ref
%type <expr_lst_t> expr_list  
%type <stmt_t> compound_stmt stmt unlabelled_stmt stmt_list
%type <stmt_pref_t> stmt_prefix 
%type <stmt_suff_t> stmt_suffix

%type <stmt_t> read_stmt write_stmt goto_stmt if_stmt assign_stmt loop_stmt
%type <intmdt_addr> cond
%type <integer> M       /* Token para conseguir número de instrução seguinte */
%type <stmt_t> N        /* Token para conseguir a quádrupla seguinte */

%%

/* descriptions of expected inputs     corresponding actions (in C) */
    /* Header e Declarações */
program                 :   PROGRAM IDENTIFIER ';' decl_list compound_stmt
    {
        // Quádrupla para finalizar: é útil quando comandos de controle são
        // os últimos ou só há um comando no programa. Não possui ação prática.
        gen(intermediate_code, "end", NULL, NULL, NULL);
        backpatch($5.next, intermediate_code->code[intermediate_code->n - 1]);
        
    }
decl_list               :   decl_list ';' decl              { q = 0; }
                        |   decl                            { q = 0; }
                        ;
decl                    :   ident_list ':' type             { installIdentList($3, $1.list); }
ident_list              :   ident_list ',' IDENTIFIER       { list_head_t* templist = list_makelist_string($3);
                                                                $$.list = list_merge($1.list, templist);
                                                                $$.qtd_terms = $1.qtd_terms + 1; }
                        |   IDENTIFIER                      { $$.list = list_makelist_string($1);
                                                            $$.qtd_terms = 1; }
                        ;
type                    :   INTEGER
                        |   REAL
                        |   BOOLEAN
                        |   CHAR
                        ;
    /* ----- Statements ----- */
compound_stmt           :   BEGIN_STMT stmt_list END { $$.next = $2.next; }
                        ;
stmt_list               :   stmt_list ';' M stmt
    {
        // Remenda o próximo do stmt_list para o primeiro do stmt
        backpatch($1.next, intermediate_code->code[$3]);
        $$.next = $4.next;
    }
                        |   stmt { $$.next = $1.next; }
                        ;
stmt                    :   label M ':' unlabelled_stmt
    {
        // Coloca um '_' ao final do label
        // Para diferenciar de identificadores comuns, por exemplo
        char* label = strdup($1);
        strncat(label, "_ _", 1);
        
        // Procura label na TS
        int res_niv;
        int res_i;
        Get_Entry(label, &res_niv, &res_i);

        if (res_i == -1){
            // Label não está na TS
            // Primeiro, temos que instalá-lo na TS
            union value dest;
            int tipo_cst = TYPE_LABEL;
            int cls = CLS_LABEL;
            boolean_list_t *blist = NULL;
            dest.gotoT = (goto_t*) malloc(sizeof(goto_t));
            if (dest.gotoT == NULL){
                fprintf(stderr, "Failed to malloc gotoT in label_stmt\n");
                YYABORT;
            }

            // Define a quádrupla de destino (quádrupla atual)
            dest.gotoT->instr_ptr = intermediate_code->code[$2];

            // Cria a lista de gotos que serão remendados
            // (por enquanto não há nenhum)
            dest.gotoT->goto_list = NULL;

            // Instala de fato na TS
            Instala(label, tipo_cst, cls, dest, blist);
        }else if(res_i != -1 
            && TabelaS[res_i].value.gotoT != NULL 
            && TabelaS[res_i].value.gotoT->instr_ptr != NULL){
            // Label está na TS e já possui um destino definido
            // Temos que acusar um erro
            
            printf("Label %s já declarado e já definido\n", $1);
            printf("Destino atual: ");
            quadruple_t* quad = TabelaS[res_i].value.gotoT->instr_ptr;
            printQuad(quad, quad->n);
            yyerror(" ");
            YYABORT;
        }else{
            // Label está na TS mas não possui um destino definido
            // Vamos definir seu destino (quádrupla atual)

            // Define a quádrupla de destino (quádrupla atual)
            TabelaS[res_i].value.gotoT->instr_ptr = intermediate_code->code[$2];

            // Faz o remendo nos gotos da lista, se houver
            list_head_t* list = TabelaS[res_i].value.gotoT->goto_list;
            backpatch(list, intermediate_code->code[$2]);
        }
        
        // Passa o next para cima o não-terminal da esquerda
        $$.next = $4.next;
    }
                        |   unlabelled_stmt { $$.next = $1.next; }
                        ;
label                   :   IDENTIFIER 
                        ;
unlabelled_stmt         :   assign_stmt { $$.next = $1.next; }
                        |   if_stmt { $$.next = $1.next; }
                        |   loop_stmt   { $$.next = $1.next; }
                        |   read_stmt   { $$.next = NULL; }
                        |   write_stmt  { $$.next = NULL; }
                        |   goto_stmt   { $$.next = $1.next; }
                        |   compound_stmt   { $$.next = $1.next; }
                        ;
assign_stmt             :   IDENTIFIER ASSIGN expr          
    { 
        // Pesquisa a entrada na tabela de símbolos
        int res_niv;
        int res_i;
        Get_Entry($1, &res_niv, &res_i);
        if (res_niv == -1){
            // Não encontrou na tabela
            yyerror("Identifier não encontrado\n");
            YYABORT;
        }

        // Tipo dos operandos (para verificação de tipos)
        int tipo1 = TabelaS[res_i].type;
        int tipo2 = $3->type;

        // Se for temporário, procure na Tabela de Símbolos seu tipo de verdade
        if (tipo1 == TS_ENTRY ){
            int idx = TabelaS[res_i].value.TS_idx;
            tipo1 = TabelaS[idx].type;
        }
        if (tipo2 == TS_ENTRY){
            int idx = $3->value.TS_idx;
            tipo2 = TabelaS[idx].type;
        }

        // Verificação de Tipos
        if (tipo1 == TYPE_REAL && tipo2 == TYPE_INT){
            // Pode colocar int em real, nada a ser feito
        }else if (tipo1 != tipo2){
            // Tentando colocar real em int, acusar erro
            typeerror_msg("Tipos incompatíveis na atribuição\n");
            YYABORT;
        }

        // Geração da Quádrupla
        if (tipo1 != TYPE_BOOL){
            // Variáveis do tipo inteiro, real e char
            // Guarde o resultado da expressão na entrada do identificador na TS
            intmdt_addr_t *dest = malloc (sizeof(intmdt_code_t));
            if (dest == NULL) {
                yyerror("Error: malloc in ASSIGN");
                YYABORT;
            }
            dest->type = TS_ENTRY;
            dest->value.TS_idx = res_i;
            gen(intermediate_code, ":=", $3, NULL, dest);
            $$.next = NULL;
        }else{
            // Variáveis do tipo booleano:

            // Guarde o resultado da expressão na entrada do identificador na TS
            // Mas tem um porém quanto ao resultado da expressão!
            intmdt_addr_t *dest = malloc (sizeof(intmdt_code_t));
            if (dest == NULL) {
                yyerror("Error: malloc in ASSIGN");
                YYABORT;
            }
            dest->type = TS_ENTRY;
            dest->value.TS_idx = res_i;

            // Existe um "if escondido" nessa atribuição:
            //      if (expr)
            //          id = true
            //      else
            //          id = false
            // As quádruplas geradas a seguir são para simular isso

            // Gerar um temporário 'true'
            // Ele será atribuído ao id se expr for verdadeiro
            intmdt_addr_t *temp1 = newtemp(TYPE_BOOL);
            TabelaS[temp1->value.TS_idx].class = CLS_VARIABLE;
            TabelaS[temp1->value.TS_idx].value.boolean = 1;

            // Quádrupla para atribuir verdadeiro ao identifier
            gen(intermediate_code, ":=", temp1, NULL, dest);

            // Remendo: caso a expressão passada seja true, atribuamos true
            // i.e. a truelist deve ir para o atribuir true 
            backpatch($3->list->truelist, 
                      intermediate_code->code[intermediate_code->n-1]);

            // Após atribuir verdadeiro, pule o atribuir falso
            gen(intermediate_code, "gotoAB", NULL, NULL, NULL);
            $$.next = list_makelist(intermediate_code->code[intermediate_code->n - 1]);

            // Gerar um temporário 'false'
            // Ele será atribuído ao id se expr for falso
            intmdt_addr_t *temp2 = newtemp(TYPE_BOOL);
            TabelaS[temp2->value.TS_idx].class = CLS_VARIABLE;
            TabelaS[temp2->value.TS_idx].value.boolean = 0;
            
            // Quádrupla para atribuir falso ao identifier
            gen(intermediate_code, ":=", temp2, NULL, dest);

            // Remendo: caso a expressão passada seja false, atribuamos false
            // i.e. a falselist deve ir para o atribuir false 
            backpatch($3->list->falselist, 
                      intermediate_code->code[intermediate_code->n-1]);

            // Não precisamos pular quádruplas agora, basta seguir a execução
        }
    }
                        ;
cond                    :   expr
                        ;
if_stmt                 :   IF cond THEN M stmt M   %prec THEN
    {
        // Se cond é verdadeiro, devemos ir para o stmt
        // i.e. remende a truelist de cond para ir para o stmt
       	backpatch($2->list->truelist, intermediate_code->code[$4]);

        // Se cond é falso, devemos ir para depois do stmt
        // i.e. devemos ir para a quádrupla seguinte ao stmt
        // Após o comando if, devemos ir para lá também,
        // por isso a atribuição a $$.next
       	$$.next = list_merge($2->list->falselist, $5.next);
        // Essa falselist será remendada quando o $$.next for remendado,
        // por exemplo no stmt_list

        // Se conhecemos a quádrupla seguinte ao stmt,
        // podemos fazer o remendo dela para seguir após o if_stmt
        if ($5.next != NULL){
            backpatch($5.next, intermediate_code->code[$6]);
        }
    }
                        |   IF cond THEN M stmt ELSE N M stmt
    {
        // Se cond é verdadeiro, devemos ir para o stmt
        // i.e. remende a truelist de cond para ir para o stmt
        backpatch($2->list->truelist, intermediate_code->code[$4]);

        // Se cond é falso, devemos ir para o stmt do else
        // i.e. remende a falselist de cond para ir para o stmt
        backpatch($2->list->falselist, intermediate_code->code[$8]);

        // Após o stmt (do then), o stmt (do else) 
        // e o N vamos para a quádrupla após o if_stmt
        list_head_t* temp = list_merge($5.next, $7.next);
        $$.next = list_merge(temp, $9.next);
    }
                        ;
M                       :   /* empty */
    {
        // Agora já sabemos o número da próxima quádrupla
        // Ele está em 'intermediate_code->n'
        $$ = intermediate_code->n;
    }
                        ;
N                       :   /* empty */
    {
        // Cria-se o goto para saltar um trecho de código à frente
        // Saberemos o destino posteriormente e o remendaremos
       	gen(intermediate_code, "gotoN", NULL, NULL, NULL);
		$$.next = list_makelist(intermediate_code->code[intermediate_code->n-1]);
    }
loop_stmt               :   M stmt_prefix M DO M stmt_list N M stmt_suffix
    {
        if (!$2.hasPrefix && !$9.hasSuffix){
            // Sem prefixo e sufixo, temos um loop infinito

            // Ao fim do corpo, faça o loop infinito
            backpatch($7.next, intermediate_code->code[$1]); 
            $$.next = NULL;   
        }else{
            // Após o corpo do loop, vá para onde N diz para ir.
            // N pode ou voltar para a condição do while 
            // ou avançar para verificar a condição do until
            backpatch($6.next, $7.next->list->value);

            // Tratamento do While, se ele existir
            list_head_t* falseWhile = NULL;
            if ($2.hasPrefix == true){
                // Lista de falso do condicional será usado para sair do loop
                // Será tratado posteriormente, no Until (ou na falta dele)

                // Backpatching para ficar no loop após o corpo
                // i.e. volte para analisar o condicional do while após o corpo
                backpatch($7.next, intermediate_code->code[$1]);

                // Backpatching para entrar no loop após avaliar verdadeiro
                // i.e. a truelist do condicional vai para a primeira quádrupla
                // do stmt_list do corpo do loop
                backpatch($2.truelist, intermediate_code->code[$5]);
            }
            
            //Tratamento do Until
            if ($9.hasSuffix == true){
                // Temos Until

                // Se condicional do Until for falso, fique no loop
                // i.e. volte para a quádrupla do condicional do While
                // (se não tiver while, ele cai na primeira instrução do corpo)
                backpatch($9.falselist, intermediate_code->code[$1]);

                // Se condicional do Until for verdadeiro, saia do loop
                // Se houver o While, junte a lista de quando ele for falso
                // para formar a lista que devemos ir após o loop_stmt
                $$.next = list_merge($9.truelist, $2.falselist);

                // Ao final do corpo, verifique o condicional do Until
                // Note que isso sobrescreve o remendo feito no While 
                // (caso tenha sido feito) que ia para verificar o condicional
                // do While
                backpatch($7.next, intermediate_code->code[$8]);
            }else{
                // Não temos Until, mas temos While 
                // (senão teria caído no loop infinito)

                // Saímos do loop quando o condicional do While for falso
                // Saberemos o destino num backpatch futuro
                $$.next = $2.falselist;
            }
        }
    }
                        ;
stmt_prefix             :   WHILE M cond M
    {
        $$.hasPrefix = true;
        $$.falselist = $3->list->falselist;
        $$.truelist = $3->list->truelist;
    }
                        |   /* vazio */
    {
        $$.hasPrefix = false;
        $$.falselist = NULL;
    }
                        ;
stmt_suffix             :   UNTIL cond
    {
        $$.truelist = $2->list->truelist;
        $$.falselist = $2->list->falselist;
        $$.hasSuffix = true;
    }
                        |   END
    {
        $$.truelist = NULL;
        $$.falselist = NULL;
        $$.hasSuffix = false;
    }
                        ;
read_stmt               :   READ '(' ident_list ')'
    {
        // TODO: necessário ident_list
        gen(intermediate_code, "TODO:read", NULL, NULL, NULL);

    }
                        ;
write_stmt              :   WRITE '(' expr_list ')'
    {
        // Iterar por toda a lista gerando um print para cada expr
        list_entry_t* current = $3.list->list;
        while(current != NULL) {
            gen(intermediate_code, "print", current->value, NULL, NULL);
            current = current->next;
        }
        $$.next = NULL;
    }
                        ;
goto_stmt               :   GOTO IDENTIFIER
    {
        // Coloca um '_' ao final do label
        // Para diferenciar de identificadores comuns, por exemplo
        char* label = strdup($2);
        strncat(label, "_ _", 1);
        
        // Procurar label na TS
        int res_niv;
        int res_i;
        Get_Entry(label, &res_niv, &res_i);

        if (res_i != -1 
            && TabelaS[res_i].value.gotoT != NULL 
            && TabelaS[res_i].value.gotoT->instr_ptr != NULL){            
            // Label está na TS
            // Destino é um label definido, basta gerar código para lá

            // Cria estrutura para a quádrupla de destino
            intmdt_addr_t *dest = malloc(sizeof(intmdt_addr_t));
            if (dest == NULL) {
                fprintf(stderr, "Failed to malloc intmdt_addr_t in goto_stmt\n");
                YYABORT;
            }

            // Pega a quádrupla destino da TS
            quadruple_t* quad = TabelaS[res_i].value.gotoT->instr_ptr;
            dest->type = TYPE_LABEL;
            dest->value.instr_ptr = quad;
            
            // Cria o goto para lá
            gen(intermediate_code, "goto", NULL, NULL, dest);
        }else{
            // Label ou não definido ou não está na tabela

            if (res_i == -1){
                // Label não está na TS
                // Primeiro, temos que instalá-lo na TS
                union value dest;
                int tipo_cst = TYPE_LABEL;
                int cls = CLS_LABEL;
                boolean_list_t *blist = NULL;
                dest.gotoT = (goto_t*) malloc(sizeof(goto_t));
                if (dest.gotoT == NULL){
                    fprintf(stderr, "Failed to malloc gotoT in goto_stmt\n");
                    YYABORT;
                }

                // Gera quádrupla com goto
                // Ela será remendada depois (quando o label for definido)
                gen(intermediate_code, "gotoV1", NULL, NULL, NULL);

                // Cria a lista de gotos que serão remendados
                // O único elemento é o goto desse stmt (criado acima)
                dest.gotoT->goto_list = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
                
                // A quádrupla de destino será definida posteriormente
                dest.gotoT->instr_ptr = NULL;

                // Instala de fato na TS
                Instala(label, tipo_cst, cls, dest, blist);
            }else{
                // Está na tabela, mas não está definido

                // Coloca um goto vazio para ser remendado depois
                // Será remendada quando o label for definido
                gen(intermediate_code, "gotoV2", NULL, NULL, NULL);

                // Adiciona esse goto na lista ser remendada depois
                list_head_t* temp_list1 = TabelaS[res_i].value.gotoT->goto_list;
                list_head_t* temp_list2 = list_makelist(intermediate_code->code[intermediate_code->n-1]);
                TabelaS[res_i].value.gotoT->goto_list = 
                                            list_merge(temp_list1, temp_list2);
            }
        }
        $$.next = NULL;
    }
                        ;
    /* ----- Expressões ----- */
expr_list               :   expr
    {
        $$.list = list_makelist_intmt($1);
        $$.qtd_terms = 1;
    }
                        |   expr_list ',' expr
    {
        list_head_t* templist = list_makelist_intmt($3);
        $$.list = list_merge($1.list, templist);
        $$.qtd_terms = $1.qtd_terms + 1;
    }
                        ;
expr                    :   simple_expr { $$ = $1; }
                        |   simple_expr RELOP simple_expr
    {
        // Se algum operando for temporário,
        // então procure na tabela seu tipo de verdade
        int tipo1 = $1->type;
        int tipo2 = $3->type;
        tempTipo(&tipo1, &tipo2, $1, $3);
        
        // Verificação de Tipos
        if (strcmp($2,"=") == 0 || strcmp($2,"!=") == 0){
            // Não importa os tipos dos operandos

            // Cria um temporário para o resultado (será substituído depois)
            intmdt_addr_t *temp = newtemp(TYPE_BOOL);
            temp->list = malloc(sizeof(boolean_list_t));
            if (temp->list == NULL) {
                fprintf(stderr, "Malloc of boolean_list_t failed! (RELOP)\n");
                YYABORT;
            }

            // "If Escondido"
            //      if (op1 RELOP op2)
            //          expr = true
            //      else
            //          expr = false
            // As quádruplas geradas a seguir são para simular isso

            // Quádrupla para avaliar o RELOP
            // Depois o resultado virará um destino para ir se for verdadeiro
            gen(intermediate_code, $2, $1, $3, temp);
            temp->list->truelist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
            
            // GOTO caso seja falso
            gen(intermediate_code, "gotoRE", NULL, NULL, NULL);
            temp->list->falselist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
            $$ = temp;
        }else if (strcmp($2,"<") == 0 || strcmp($2,"<=") == 0 
               || strcmp($2,">") == 0 || strcmp($2,">=") == 0){
            // Operandos devem ser números
            if (!isNumber(tipo1) && !isNumber(tipo2)){
                typeerror();
                YYABORT;
            }
            
            // Cria um temporário para o resultado (será substituído depois)
            intmdt_addr_t *temp = newtemp(TYPE_BOOL);
            temp->list = malloc(sizeof(boolean_list_t));
            if (temp->list == NULL) {
                fprintf(stderr, "Malloc of boolean_list_t failed! (RELOP)\n");
                YYABORT;
            }

            // "If Escondido"
            //      if (op1 RELOP op2)
            //          expr = true
            //      else
            //          expr = false
            // As quádruplas geradas a seguir são para simular isso

            // Quádrupla para avaliar o RELOP
            // Depois o resultado virará um destino para ir se for verdadeiro
            gen(intermediate_code, $2, $1, $3, temp);
            temp->list->truelist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
            
            // GOTO caso seja falso
            gen(intermediate_code, "gotoRG", NULL, NULL, NULL);
            temp->list->falselist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
            $$ = temp;
        }else{
            printf("Lexema RELOP não encontrado\n");
            YYABORT;
        }
    }
                        ;
simple_expr             :   term { $$ = $1; }
                        |   simple_expr ADDOP term
    {
        if (strcmp($2,"+") == 0){
            // Se algum for temporário, procure na tabela seu tipo de verdade
            int tipo1 = $1->type;
            int tipo2 = $3->type;
            tempTipo(&tipo1, &tipo2, $1, $3);
            
            // Verificação de Tipos + Geração da Quádrupla
            if (isNumber(tipo1) && isNumber(tipo2)){
                if (tipo1 == TYPE_INT && tipo2 == TYPE_INT){
                    // Dois inteiros => resultado inteiro
       	     		intmdt_addr_t *temp = newtemp(TYPE_INT);
                    gen(intermediate_code, "+", $1, $3, temp);
                    $$ = temp;
                }else{
                    // Pelo menos um real => resultado real
       	     		intmdt_addr_t *temp = newtemp(TYPE_REAL);
                    gen(intermediate_code, "+", $1, $3, temp);
                    $$ = temp;
                }
            }else{
                typeerror();
                YYABORT;
            }
        }else{
            printf("Lexema ADDOP não encontrado: %s\n", $2);
            yyerror("");
            YYABORT;
        }
    }
                        |   simple_expr OR M term
    {
        // Se algum for temporário, procure na tabela seu tipo de verdade
        int tipo1 = $1->type;
        int tipo2 = $4->type;
        tempTipo(&tipo1, &tipo2, $1, $4);
        
        // Verificação de Tipos + Geração da Quádrupla
        if (tipo1 == TYPE_BOOL && tipo2 == TYPE_BOOL){
            // Remendo do falselist do primeiro 
            // com a primeira quádrupla do segundo 
            // i.e. se o primeiro for falso, avalie o segundo
            backpatch($1->list->falselist, intermediate_code->code[$3]);
            
            // Se o segundo também for falso, a expressão é falsa
            // i.e. E.falselist = E2.falselist
            // (o temp virará o $$ logo em seguida)
            intmdt_addr_t *temp = newtemp(TYPE_BOOL);
            temp->list = malloc(sizeof(boolean_list_t));
            if (temp->list == NULL) {
                fprintf(stderr, "Malloc of boolean_list_t failed! (OR)\n");
                YYABORT;
            }
            temp->list->falselist = $4->list->falselist;

            // Se algum for verdadeiro, a expressão é verdadeira
            // i.e. E.truelist = merge(E1.truelist, E2.truelist)
            temp->list->truelist = list_merge($1->list->truelist,
                                                $4->list->truelist);
            $$ = temp;
        }else{
            typeerror();
            YYABORT;
        }
    }
                        |   simple_expr MINUS term
    {
        // Se algum for temporário, procure na tabela seu tipo de verdade
        int tipo1 = $1->type;
        int tipo2 = $3->type;
        tempTipo(&tipo1, &tipo2, $1, $3);
        
        // Verificação de Tipos + Geração da Quádrupla
        if (isNumber(tipo1) && isNumber(tipo2)){
            if (tipo1 == TYPE_INT && tipo2 == TYPE_INT){
                // Dois inteiros => resultado inteiro
                intmdt_addr_t *temp = newtemp(TYPE_INT);
                gen(intermediate_code, "-", $1, $3, temp);
                $$ = temp;
            }else{
                // Pelo menos um real => resultado real
                intmdt_addr_t *temp = newtemp(TYPE_REAL);
                gen(intermediate_code, "-", $1, $3, temp);
                $$ = temp;
            }
        }else{
            typeerror();
            YYABORT;
        }
    }
                        ;
term                    :   factor_a { $$ = $1; } 
                        |   term MULOP factor_a
    {
        // Se algum for temporário, procure na tabela seu tipo de verdade
        int tipo1 = $1->type;
        int tipo2 = $3->type;
        tempTipo(&tipo1, &tipo2, $1, $3);
            
        if (strcmp($2,"*") == 0){
            // Verificação de Tipos + Geração da Quádrupla
            if (isNumber(tipo1) && isNumber(tipo2)){
                if (tipo1 == TYPE_INT && tipo2 == TYPE_INT){
                    // Dois inteiros => resultado inteiro
                    intmdt_addr_t *temp = newtemp(TYPE_INT);
                    gen(intermediate_code, "*", $1, $3, temp);
                    $$ = temp;
                }else{
                    // Pelo menos um real => resultado real
                    intmdt_addr_t *temp = newtemp(TYPE_REAL);
                    gen(intermediate_code, "*", $1, $3, temp);
                    $$ = temp;
                }
            }else{
                typeerror();
                YYABORT;
            }
        }else if(strcmp($2,"/") == 0){
            // Verificação de Tipos + Geração da Quádrupla
            if (isNumber(tipo1) && isNumber(tipo2)){
                // Resultado sempre é real
                intmdt_addr_t *temp = newtemp(TYPE_REAL);
                gen(intermediate_code, "/", $1, $3, temp);
                $$ = temp;
            }else{
                typeerror();
                YYABORT;
            }
        }else if (strcmp($2,"div") == 0){
            // Verificação de Tipos + Geração da Quádrupla
            if (tipo1 == TYPE_INT && tipo2 == TYPE_INT){
                // Divisão inteira => resultado inteiro
                intmdt_addr_t *temp = newtemp(TYPE_INT);
                gen(intermediate_code, "div", $1, $3, temp);
                $$ = temp;
            }else{
                typeerror();
                YYABORT;
            }
        }else if (strcmp($2,"mod") == 0){
            // Verificação de Tipos + Geração da Quádrupla
            if (tipo1 == TYPE_INT && tipo2 == TYPE_INT){
                // Resultado sempre é inteiro
                intmdt_addr_t *temp = newtemp(TYPE_INT);
                gen(intermediate_code, "mod", $1, $3, temp);
                $$ = temp;
            }else{
                typeerror();
                YYABORT;
            }
        }else{
            printf("Lexema MULOP não encontrado: %s\n", $2);
            yyerror("");
            YYABORT;
        }
    }
                        |   term AND M factor_a
    {
        // Se algum for temporário, procure na tabela seu tipo de verdade
        int tipo1 = $1->type;
        int tipo2 = $4->type;
        tempTipo(&tipo1, &tipo2, $1, $4);
        
        // Verificação de Tipos + Geração da Quádrupla
        if (tipo1 == TYPE_BOOL && tipo2 == TYPE_BOOL){
            // Se o primeiro for verdadeiro, avalie o segundo
            // i.e. remende o truelist do primeiro 
            // com a primeira quádrupla do segundo
            backpatch($1->list->truelist, intermediate_code->code[$3]);

            // Se o segundo também for verdadeiro, o resultado é verdadeiro
            // i.e. E.truelist = E2.truelist
            // (o temp virará o $$ logo em seguida)
            intmdt_addr_t *temp = newtemp(TYPE_BOOL);
            temp->list = malloc(sizeof(boolean_list_t));
            if (temp->list == NULL) {
                fprintf(stderr, "Malloc of boolean_list_t failed! (AND)\n");
                YYABORT;
            }
            temp->list->truelist = $4->list->truelist;

            // Se algum for falso, a expressão é falsa
            // i.e. E.falselist = merge(E1.falselist, E2.falselist)
            temp->list->falselist = list_merge($1->list->falselist,
                                                $4->list->falselist);
            $$ = temp;
        }else{
            typeerror();
            YYABORT;
        }
    }
function_ref            :   IDENTIFIER_F '(' expr_list ')'
    {
        // Tratamento Quantidade de Argumentos
        int args = $3.qtd_terms;
        char buf[50];
        if (args > 1){
            // Nenhuma função tem mais de um argumento
            sprintf(buf, "Muitos argumentos para %s\n", $1);
            yyerror(buf);
            YYABORT;
        }else if(args == 0 && 
            !(
                (strcmp($1,"eoln") == 0)
                && (strcmp($1,"eof") == 0)
            )){
            // Só Eof e Eoln devem ser invocadas sem argumento
            sprintf(buf, "Poucos argumentos para %s\n", $1);
            yyerror(buf);
            YYABORT;
        }else if(args == 1 && 
            (
                (strcmp($1,"eoln") == 0)
                || (strcmp($1,"eof") == 0)
            )){
            // Eof e Eoln devem ser invocadas sem argumento
            sprintf(buf, "Muitos argumentos para %s\n", $1);
            yyerror(buf);
            YYABORT;
        }
        
        // Tratando argumentos que são temporários, se houver, 
        // para a verificação de tipos
        intmdt_addr_t* arg;
        int tipo1;
        if (args == 1){
            // Argumento passado
            arg = $3.list->list->value;

            // Se ele for temporário, pegue o tipo verdadeiro na TS
            tipo1 = arg->type;
            if (tipo1 == TS_ENTRY){
                int idx = arg->value.TS_idx;
                tipo1 = TabelaS[idx].type;
            }
        }

        // Verificação de Tipos + Geração da Quádrupla
        if (isNumToReal($1)){
            // Funções que recebem um número (int ou real) e produzem um real
            if (tipo1 != TYPE_REAL && tipo1 != TYPE_INT){
                typeerror_msg($1);
                YYABORT;
            }
            intmdt_addr_t *temp = newtemp(TYPE_REAL);
            gen(intermediate_code, $1, arg, NULL, temp);
            $$ = temp;

        }else if (strcmp($1,"abs") == 0){
            intmdt_addr_t *temp;
            if (tipo1 == TYPE_REAL){
                temp = newtemp(TYPE_REAL);
            }else if(tipo1 == TYPE_INT){
                temp = newtemp(TYPE_INT);
            }else{
                typeerror_msg($1);
                YYABORT;
            }
            gen(intermediate_code, "abs", arg, NULL, temp);
            $$ = temp;

        }else if (strcmp($1,"ord") == 0){
            // Retorna o inteiro do parâmetro
            // É um "casting" de inteiro

            if (tipo1 == TYPE_REAL){
                typeerror_msg($1);
                YYABORT;
            }
            intmdt_addr_t *temp = newtemp(TYPE_INT);
            gen(intermediate_code, "ord", arg, NULL, temp);
            $$ = temp;

        }else if (strcmp($1,"chr") == 0){
            // Retorna equivalente char do parâmetro
            // É um "casting" de char

            if (tipo1 == TYPE_REAL || tipo1 == TYPE_BOOL){
                typeerror();
                YYABORT;
            }
            intmdt_addr_t *temp = newtemp(TYPE_CHAR);
            gen(intermediate_code, "chr", arg, NULL, temp);
            $$ = temp;

        }else{
            printf("Função não encontrada: %s\n", $1);
            yyerror("");
            YYABORT;
        }
    }
                        |   IDENTIFIER_F
    {
        // EOF e EOLN

        // Não há tipos a verificar, pois não há parâmetros

        // Temporário para resultado + gerência de truelist/falselist
        intmdt_addr_t *temp = newtemp(TYPE_BOOL);
        temp->list = malloc(sizeof(boolean_list_t));
        if (temp->list == NULL) {
            fprintf(stderr, "Malloc of boolean_list_t failed! (funct)\n");
            YYABORT;
        }
        
        // "If Escondido"
        //      if (eof)
        //          function_ref = true
        //      else
        //          function_ref = false
        // As quádruplas geradas a seguir são para simular isso

        // Quádrupla para avaliar o resultado da função
        // Depois o resultado virará um destino para ir se for verdadeiro
        gen(intermediate_code, $1 , NULL, NULL, temp);
        temp->list->truelist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
        
        // GOTO caso seja falso
        gen(intermediate_code, "gotoF", NULL, NULL, NULL);
        temp->list->falselist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
        $$ = temp;
    }
                        ;
factor_a                :   MINUS factor
    { 
        // Se algum for temporário, procure na tabela seu tipo de verdade
        int tipo1 = $2->type;
        if (tipo1 == TS_ENTRY){
            int idx = $2->value.TS_idx;
            tipo1 = TabelaS[idx].type;
        }
        
        // Verificação de Tipos
        intmdt_addr_t *temp;
        if (tipo1 == TYPE_INT){
            temp = newtemp(TYPE_INT);
        }else if (tipo1 == TYPE_REAL){
            temp = newtemp(TYPE_REAL);
        }else{
            typeerror();
            YYABORT;
        }

        // Geração da Quádrupla
        gen(intermediate_code, "-1", $2, NULL, temp);
        $$ = temp;
    }                      
                        |   factor { $$ = $1; }
                        ;
factor                  :   IDENTIFIER
    { 
        // Pesquisa a entrada na tabela de símbolos (TS)
        int res_niv;
        int res_i;
        Get_Entry($1, &res_niv, &res_i);
        if (res_niv == -1){
            // Não encontrou na tabela
            YYABORT;
        }

        // Estrutura para carregar o identificador da TS
        intmdt_addr_t *dest = malloc (sizeof(intmdt_code_t));
        if (dest == NULL) {
            fprintf(stderr,"Error: could not malloc dest in 'factor -> identifier'");
            YYABORT;
        }
        dest->type = TS_ENTRY;
        dest->value.TS_idx = res_i;

        TabelaS[res_i].class = CLS_VARIABLE;
        boolean_list_t *list = NULL;
        if (TabelaS[res_i].type == TYPE_BOOL){
            // Se for booleano, temos que tomar mais cuidado

            // Cria um temporário para a avaliação do valor da variável booleana
            // (será substituído depois)
            intmdt_addr_t *temp = newtemp(TYPE_BOOL);
            temp->list = malloc(sizeof(boolean_list_t));
            if (temp->list == NULL) {
                fprintf(stderr, "Malloc of boolean_list_t failed! (factor -> id)\n");
                exit(1);
            }
            // "If Escondido"
            //      if (id)
            //          factor = true
            //      else
            //          factor = false
            // As quádruplas geradas a seguir são para simular isso

            // Quádrupla para avaliar o valor que está na TS
            // Depois o resultado virará um destino para ir se for verdadeiro
            gen(intermediate_code, "boolV", dest, NULL, temp); 
            temp->list->truelist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
            
            // GOTO caso seja falso
            gen(intermediate_code, "gotoB", NULL, NULL, NULL);
            temp->list->falselist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
            $$ = temp;
        }else{
            // Simplesmente passa ele para o factor
            $$ = dest;
        }
    }
                        |   constant        { $$ = $1; }
                        |   '(' expr ')'    { $$ = $2; }
                        |   function_ref    { $$ = $1; }
                        |   NOT factor
    { 
        // Verificação de Tipos
        int tipo1 = $2->type;
        if (tipo1 == TS_ENTRY){
            int idx = $2->value.TS_idx;
            tipo1 = TabelaS[idx].type;
        }
        if (tipo1 != TYPE_BOOL){
            typeerror();
            YYABORT;
        }
        
        // Temporário para ser colocado no não-terminal da esquerda
        intmdt_addr_t *temp = newtemp(TYPE_BOOL);
        temp->list = malloc(sizeof(boolean_list_t));
        if (temp->list == NULL) {
            fprintf(stderr, "Malloc of boolean_list_t failed! (NOT)\n");
            YYABORT;
        }

        // Basta inverter as listas truelist e falselist
        temp->list->truelist = $2->list->falselist;
        temp->list->falselist = $2->list->truelist;
        $$ = temp;
    }
                        ;
constant                :   INT_CONSTANT            
                            {
                                // Busca na TS e coloca no não-terminal
                                intmdt_addr_t *temp = newtemp(TYPE_INT);
                                TabelaS[temp->value.TS_idx].class = CLS_CST;
                                TabelaS[temp->value.TS_idx].value.integer = $1;
                                $$ = temp;
                                $$->list = NULL;
                            }
                        |   REAL_CONSTANT
                            { 
                                // Busca na TS e coloca no não-terminal
                                intmdt_addr_t *temp = newtemp(TYPE_REAL);
                                TabelaS[temp->value.TS_idx].class = CLS_CST;
                                TabelaS[temp->value.TS_idx].value.real = $1;
                                $$ = temp;
                                $$->list = NULL;
                            }
                        |   CHAR_CONSTANT
                            { 
                                // Busca na TS e coloca no não-terminal
                                intmdt_addr_t *temp = newtemp(TYPE_CHAR);
                                TabelaS[temp->value.TS_idx].class = CLS_CST;
                                TabelaS[temp->value.TS_idx].value.character = $1;
                                $$ = temp;
                                $$->list = NULL;
                            }
                        |   boolean_constant { $$ = $1; }
                        ;
boolean_constant        :   TRUE_CST
    { 
        // Temporário que será o não-terminal da esquerda
        // Ele guarda o booleano true
        intmdt_addr_t *temp = newtemp(TYPE_BOOL);
        TabelaS[temp->value.TS_idx].class = CLS_CST;
        TabelaS[temp->value.TS_idx].value.boolean = $1;
        temp->list = malloc(sizeof(boolean_list_t));
        if (temp->list == NULL) {
            fprintf(stderr, "Malloc of boolean_list_t failed!\n");
            YYABORT;
        }

        // Quádrupla do "If escondido":
        //      if (true)
        //          constant = true
        //      /* não existe else! */

        gen(intermediate_code, "gotoT", NULL, NULL, NULL);
        quadruple_t* quad = intermediate_code->code[intermediate_code->n - 1];
        
        // Ele só possui uma truelist
        temp->list->truelist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
        temp->list->falselist = NULL;
        $$ = temp;
    }                   
                        |   FALSE_CST
    { 
        intmdt_addr_t *temp = newtemp(TYPE_BOOL);
        TabelaS[temp->value.TS_idx].class = CLS_CST;
        TabelaS[temp->value.TS_idx].value.boolean = $1;
        temp->list = malloc(sizeof(boolean_list_t));
        if (temp->list == NULL) {
            fprintf(stderr, "Malloc of boolean_list_t failed!\n");
            YYABORT;
        }

        // Quádrupla do "If escondido":
        //      if (true)
        //          /* não existe */
        //      else
        //          constant = false
        //      

        gen(intermediate_code, "gotoF", NULL, NULL, NULL);
        quadruple_t* quad = intermediate_code->code[intermediate_code->n - 1];
        
        // Ele só possui uma falselist
        temp->list->truelist = NULL;
        temp->list->falselist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
        $$ = temp;
    }
                        ;


%%                     

/*
Instala a lista de identificadores 'id_list' (global) de tipo 'type' na 
tabela de símbolos
*/
void installIdentList(char* type, list_head_t* list){
    //   Obs.: o tamanho do array 'id_list' está na variável global 'q'
    int i = 0;
    // printf("%i declaracoes do tipo %s\n", q, type);
    list_entry_t* current = list->list;
    while (current != NULL){
        // printf("Instalando %s, do tipo %s\n", id_list[i], type);
        union value placeholder;
        int tipo_cst = -1;
        int cls = -1;
        boolean_list_t *blist = NULL;
        if (strcmp(type, "integer") == 0){
            tipo_cst = TYPE_INT;
            cls = CLS_VARIABLE;
        }else if (strcmp(type, "real") == 0){
            tipo_cst = TYPE_REAL;
            cls = CLS_VARIABLE;
        }else if (strcmp(type, "boolean") == 0){
            cls = CLS_VARIABLE;
            tipo_cst = TYPE_BOOL;
            blist = malloc(sizeof(boolean_list_t));
            if (blist == NULL) {
                fprintf(stderr, "Malloc of boolean_list_t failed!\n");
                exit(1);
            }
        }else if (strcmp(type, "char") == 0){
            cls = CLS_VARIABLE;
            tipo_cst = TYPE_CHAR;
        }
        Instala(current->value, tipo_cst, cls, placeholder, blist);
        current = current->next;
    }
}

/*
Atualiza o atributo 'value' da entrada 'id' da tabela de símbolos
*/
void updateVal(char* id, char* value){
    int res_niv;
    int res_i;
    Get_Entry(id, &res_niv, &res_i);

    // O correto seria:
    // strcpy(TabelaS[res_i]->value, value);

    // Ainda não avaliamos expressões para conseguir calcular o value
    // mas podemos testar o updateVal, colocando o contador 'novoVal' na tabela
    char num[200];
    sprintf(num, "%d", novoVal);
    /* strcpy(TabelaS[res_i]->value, num); */
    TabelaS[res_i].value.integer = atoi(num);

    novoVal++;
}

int main (void) {
    #if YYDEBUG
        yydebug = 1;     
    #endif 


    /* Inicialização da Tabela de Símbolos */
    /* Primeira posição da tabela é 1. L é o final da árvore */
    L = 1;             
    /* Primeiro nível é 1 */     
    nivel = 1;              
    /* escopo[1] contém o indice do primeiro elemento */
    escopo[nivel] = 0;      

    /* Inicialização da lista de quádruplas */
    intermediate_code = init_code();

    /* Parsing */
    printf("Parsing...\n");
    if (yyparse() == 0){
        printf("Parse sucessful\n\n");
        /* printf("Tabela de Simbolos Final:"); */
        imprimir();     // Imprime a tabela de símbolos ao final
        print_intmdt_code(intermediate_code);
        free_intmdt_code(intermediate_code);
        return 0;
    }else{
        free_intmdt_code(intermediate_code);
        return 1;
    }
}

/* 
Se algum tipo for temporário (apontar para a tabela de símbolos) busca na 
tabela de símbolos o tipo verdadeiro
*/
void tempTipo(int* tipo1, int* tipo2, intmdt_addr_t* s1, intmdt_addr_t* s3){
    if (*tipo1 == TS_ENTRY){
        int idx = s1->value.TS_idx;
        *tipo1 = TabelaS[idx].type;
    }
    if (*tipo2 == TS_ENTRY){
        int idx = s3->value.TS_idx;
        *tipo2 = TabelaS[idx].type;
    }
}

/* Verifica se o tipo passado é um número (inteiro ou real) */
bool isNumber(int tipo){
    return (tipo == TYPE_INT || tipo == TYPE_REAL);
}

/* 
Verifica se função é simples "número->real"
Estão nesse conjunto: sin, cos, log, exp, sqrt 
Isso facilita verificação de tipos
*/
bool isNumToReal(char* funct){
    if (
        strcmp(funct, "sqrt") == 0
        ||  strcmp(funct, "sin") == 0
        ||  strcmp(funct, "cos") == 0
        ||  strcmp(funct, "log") == 0
        ||  strcmp(funct, "exp") == 0
        ||  strcmp(funct, "exp") == 0
    ){
        return true;
    }else{
        return false;
    }
}

void yyerror (char *s) {
    fprintf(stderr, "%s\n", s);
    fprintf(stderr,"At line %d\n",yylineno);
}

void typeerror(){
    yyerror("Type-error!");
}
void typeerror_msg(char* msg){
    printf("Type-error: %s \n ", msg);
    yyerror("");
}