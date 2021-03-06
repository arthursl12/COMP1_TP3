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
    void installIdentList(char* type);
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
    list_head_t* lhead;
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
%token <boolean> BOOL_CONSTANT TRUE_CST FALSE_CST
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

/* Tokens de Funções Padrão */
%token SIN LOG COS
%token ORD CHR
%token ABS SQRT EXP
%token EOF_TOKEN EOLN

/* Símbolo de partida */
%start program

/* Associatividade e Precedência */
%left ADDOP MINUS MULOP AND OR
%nonassoc RELOP
%nonassoc THEN
%nonassoc ELSE

/* Tipos de alguns símbolos Não-terminais */
%type <string> type decl ident_list label
%type <intmdt_addr> constant factor factor_a expr simple_expr term
%type <intmdt_addr> function_ref
%type <expr_lst_t> expr_list  
%type <stmt_t> compound_stmt stmt unlabelled_stmt stmt_list
%type <stmt_pref_t> stmt_prefix 
%type <stmt_suff_t> stmt_suffix

%type <stmt_t> read_stmt write_stmt goto_stmt if_stmt assign_stmt loop_stmt
%type <intmdt_addr> cond
%type <integer> M       /* Token para conseguir número de instrução seguinte */
%type <stmt_t> N         /* Token para conseguir a quádrupla seguinte */

%%

/* descriptions of expected inputs     corresponding actions (in C) */
    /* Header e Declarações */
program                 :   PROGRAM IDENTIFIER ';' decl_list compound_stmt 
decl_list               :   decl_list ';' decl              { q = 0; }
                        |   decl                            { q = 0; }
                        ;
decl                    :   ident_list ':' type             { installIdentList($3); $$ = $1; }
ident_list              :   ident_list ',' IDENTIFIER       { id_list[q] = $3; q++; }
                        |   IDENTIFIER                      { id_list[q] = $1; q++; }
                        ;
type                    :   INTEGER
                        |   REAL
                        |   BOOLEAN
                        |   CHAR
                        ;
    /* ----- Statements ----- */
compound_stmt           :   BEGIN_STMT stmt_list END
    {
        $$.next = $2.next;
    }
                        ;
stmt_list               :   stmt_list ';' M stmt
    {
        backpatch($1.next, intermediate_code->code[$3]);
        $$.next = $4.next;
    }
                        |   stmt
    {
        $$.next = $1.next;
    }
                        ;
stmt                    :   label M ':' unlabelled_stmt
    {
        // Coloca um '_' ao final, para diferenciar de identificadores comuns
        printf("Labelled_stmt\n");
        char* label = strdup($1);
        strncat(label, "_ _", 1);
        
        // Procura label na TS
        int res_niv;
        int res_i;
        Get_Entry(label, &res_niv, &res_i);
        if (res_niv != -1){
            yyerror("Label já existente");
            YYABORT;
        }

        // Instala o label na TS
        union value dest;
        int tipo_cst = TYPE_LABEL;
        int cls = CLS_LABEL;
        boolean_list_t *blist = NULL;

        // Pega a quádrupla de destino
        dest.instr_ptr = intermediate_code->code[$2];
        Instala(label, tipo_cst, cls, dest, blist);
        
        $$.next = $4.next;
    }
                        |   unlabelled_stmt
    {
        $$.next = $1.next;
    }
                        ;
label                   :   IDENTIFIER 
                        ;
unlabelled_stmt         :   assign_stmt
    {
        $$.next = $1.next;
    }
                        |   if_stmt
    {
        printf("unl_stmt -> if_stmt\n");
        // "Testar uma varíável advinda de uma expressão booleana!"
        // "Misturar and e or"
        $$.next = $1.next;
    }
                        |   loop_stmt   { $$.next = $1.next; }
                        |   read_stmt   { $$.next = NULL; }
                        |   write_stmt  { $$.next = $1.next; }
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
            exit(1);
        }

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
            printf("IDType: %i\n", TabelaS[res_i].type);
            printf("ExprType: %i\n", $3->type);
            typeerror();
            YYABORT;
        }

        // Geração da Quádrupla
        printf("IDENTIFIER := expr\n");
        if (tipo1 != TYPE_BOOL){
            intmdt_addr_t *dest = malloc (sizeof(intmdt_code_t));
            if (dest == NULL) {
                yyerror("Error: malloc in ASSIGN");
                YYABORT;
            }
            dest->type = TS_ENTRY;
            dest->value.TS_idx = res_i;
            gen(intermediate_code, ":=", $3, NULL, dest);
            $$.next = NULL;     // S.next = null
        }else{
            printf("> Assign de variável booleana\n");
            printf(">> Gerando destino da TS\n");
            intmdt_addr_t *dest = malloc (sizeof(intmdt_code_t));
            if (dest == NULL) {
                yyerror("Error: malloc in ASSIGN");
                YYABORT;
            }
            dest->type = TS_ENTRY;
            dest->value.TS_idx = res_i;

            printf("> Assign de variável booleana\n");
            printf(">> Gerando assign true\n");
            // Gerar um assign true
            intmdt_addr_t *temp1 = newtemp(TYPE_BOOL);
            TabelaS[temp1->value.TS_idx].class = CLS_VARIABLE;
            TabelaS[temp1->value.TS_idx].value.boolean = 1;
            gen(intermediate_code, ":=", temp1, NULL, dest);
            printf(">> Backpatch truelist da expr para assign true\n");
            backpatch($3->list->truelist, 
                      intermediate_code->code[intermediate_code->n-1]);
            printf(">> Goto para saltar o assign false\n");
            gen(intermediate_code, "gotoAB", NULL, NULL, NULL);
            $$.next = list_makelist(intermediate_code->code[intermediate_code->n - 1]);

            printf(">> Gerando assign false\n");
            // Gerar um assign false
            intmdt_addr_t *temp2 = newtemp(TYPE_BOOL);
            TabelaS[temp2->value.TS_idx].class = CLS_VARIABLE;
            TabelaS[temp2->value.TS_idx].value.boolean = 0;
            gen(intermediate_code, ":=", temp2, NULL, dest);
            printf(">> Backpatch false da expr para assign false\n");
            backpatch($3->list->falselist, 
                      intermediate_code->code[intermediate_code->n-1]);
        }
    }
                        ;
cond                    :   expr
                        ;
if_stmt                 :   IF cond THEN M stmt M   %prec THEN
    {
        printf("if_stmt -> if cond M THEN stmt\n");
        printf("stmt.next:\n");
        if ($5.next != NULL)
            printList($5.next);

        // backpatch(E.trueList, M.quad);
       	backpatch($2->list->truelist, intermediate_code->code[$4]);
       	$$.next = list_merge($2->list->falselist, $5.next);

        printf("Other Stmt: %i\n", $6);
        if ($5.next != NULL){
            backpatch($5.next, intermediate_code->code[$6]);
            printf("Done!\n");
        }

        printf("ss.next:\n");
        if ($$.next != NULL)
            printList($$.next);
    }
                        |   IF cond THEN M stmt ELSE N M stmt
    {
        printf("if_stmt -> if cond THEN M stmt N ELSE M stmt N\n");
        // backpatch(E.trueList, M1.quad);
        printf("Backpatch True\n");
        backpatch($2->list->truelist, intermediate_code->code[$4]);
        // backpatch(E.falseList,M2.quad);
        printf("Backpatch False\n");
        backpatch($2->list->falselist, intermediate_code->code[$8]);

        // temp = merge(S1.nextlist, N.nextlist);
        list_head_t* temp = list_merge($5.next, $7.next);
        $$.next = list_merge(temp, $9.next);
    }
                        ;
M                       :   /* empty */
    {
        printf("Próxima instrução disponível: %i\n", intermediate_code->n);
        $$ = intermediate_code->n;
    }
                        ;
N                       :   /* empty */
    {
        printf("I should be doing stuff right now...\n");
       	gen(intermediate_code, "gotoN", NULL, NULL, NULL);
		$$.next = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
    }
loop_stmt               :   M stmt_prefix M DO M stmt_list N M stmt_suffix
    {
        printf(">Estamos num loop\n");
        if (!$2.hasPrefix && !$9.hasSuffix){
            printf(">> Num loop infinito!\n");

            // Ao fim do corpo, faça o loop infinito
            backpatch($7.next, intermediate_code->code[$1]); 
            $$.next = NULL;   
        }else{
            // // Tratamento do While
            // if ($1 == $3){
            //     // Não possui while
            // }else{
            //     // Possui while
            //     backpatch($6.next, intermediate_code->code[$1]);    // Fazer o loop
            // }
            printf(">> Temos WHILE?\n");
            list_head_t* falseWhile = NULL;
            // Tratamento do While
            if ($2.hasPrefix == true){
                printf(">>> Sim\n");
                printf(">>> Lista de Falso do WHILE: \n");
                printList($2.falselist);
                falseWhile = $2.falselist;     // Para fazer o loop
                printf(">>> Backpatching para ficar no WHILE se verdadeiro: \n");
                backpatch($7.next, intermediate_code->code[$1]);    // Ao fim do corpo, faça o loop
                printf(">>> Backpatching para entrar no loop \n");
                backpatch($2.truelist, intermediate_code->code[$5]);
            }else{
                printf(">>> Não\n");
                // ignore
            }
            
            
            //Tratamento do Until
            printf(">> Temos UNTIL?\n");
            if ($9.hasSuffix == true){
                printf(">>> Sim\n");
                backpatch($9.falselist, intermediate_code->code[$1]);   // Se cond falso, volte para o loop
                $$.next = list_merge($9.truelist, $2.falselist);        // Senão, pode sair
                backpatch($7.next, intermediate_code->code[$8]);    // Ao fim do corpo, faça o loop

            }else{
                printf(">>> Não\n");
                $$.next = $2.falselist;
            }
        }
        
        


        // // Tratamento do Until
        // if ($7.loop_main_next_list == NULL){
        //     // Não possui UNTIL
        //     $$.next = list_merge($7.next, $2.loop_main_next_list);
        // }else{
        //     // UNTIL está presente
        //     $$.next = list_merge($7.loop_main_next_list, $2.loop_main_next_list);
        //     backpatch($7->list->falselist, intermediate_code->code[$$.loop_idx]);

        // }
    }
                        ;
stmt_prefix             :   WHILE M cond M
    {
        // WHILE m '(' bool ')' m stmt 
        printf("> Avaliando o WHILE\n");

        $$.hasPrefix = true;
        $$.falselist = $3->list->falselist;
        $$.truelist = $3->list->truelist;

        // // Goto para voltar ao início e testar as condições novamente
        // intmdt_addr_t *temp = malloc(sizeof(intmdt_addr_t));
        // temp->type = TYPE_LABEL;
        // temp->value.instr_ptr = intermediate_code->code[$2];
        // gen(intermediate_code, "gotoW", NULL, NULL, temp);
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
    }
                        ;
write_stmt              :   WRITE '(' expr_list ')'
    {
        // Iterar por toda a lista gerando um print para cada expr
        printListIntmt($3.list);
        
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
        // Coloca um '_' ao final, para diferenciar de identificadores comuns
        printf("Labelled_stmt\n");
        char* label = strdup($2);
        strncat(label, "_ _", 1);
        
        int res_niv;
        int res_i;
        Get_Entry(label, &res_niv, &res_i);
        if (res_niv == -1){
            // Não encontrou na tabela
            yyerror("Label não encontrado");
            YYABORT;
        }

        // Pega o destino da TS
        intmdt_addr_t *dest = malloc(sizeof(intmdt_addr_t));
        if (dest == NULL) {
            fprintf(stderr, "failed to malloc intmdt_addr_t in goto_stmt\n");
            YYABORT;
        }

        quadruple_t* quad = TabelaS[res_i].value.instr_ptr;
        printQuad(quad, quad->n);
        // intmdt_addr_print(((quadruple_t*)current->value)->result);
        
        dest->type = TYPE_LABEL;
        dest->value.instr_ptr = quad;
        
        gen(intermediate_code, "goto", NULL, NULL, dest);
    }
                        ;
    /* ----- Expressões ----- */
expr_list               :   expr
    {
        printf("expr_list -> expr\n");
        $$.list = list_makelist_intmt($1);
        $$.qtd_terms = 1;
    }
                        |   expr_list ',' expr
    {
        printf("expr_list -> expr_list , expr\n");
        list_head_t* templist = list_makelist_intmt($3);
        $$.list = list_merge($1.list, templist);
        $$.qtd_terms = $1.qtd_terms + 1;
        printf("Total de termos: %i\n",$$.qtd_terms);
    }
                        ;
expr                    :   simple_expr
    { 
        $$ = $1; 
    }
                        |   simple_expr RELOP simple_expr
    {
        // Se algum for temporário, procure na tabela seu tipo de verdade
        int tipo1 = $1->type;
        int tipo2 = $3->type;
        tempTipo(&tipo1, &tipo2, $1, $3);
        
        // Verificação de Tipos
        if (strcmp($2,"=") == 0 || strcmp($2,"!=") == 0){
            // Não importa os tipos dos operandos
            printf("simple_expr RELOP (%s) simple_expr\n", $2);
            intmdt_addr_t *temp = newtemp(TYPE_BOOL);
            temp->list = malloc(sizeof(boolean_list_t));
            if (temp->list == NULL) {
                fprintf(stderr, "Malloc of boolean_list_t failed! (RELOP)\n");
                YYABORT;
            }
            gen(intermediate_code, $2, $1, $3, temp);
            temp->list->truelist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
            gen(intermediate_code, "gotoRE", NULL, NULL, NULL);
            temp->list->falselist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
            $$ = temp;
            // TODO: criar quádrupla para calcular valor
            // $$->value = $1->value; 
        }else if (strcmp($2,"<") == 0 || strcmp($2,"<=") == 0 
               || strcmp($2,">") == 0 || strcmp($2,">=") == 0){
            if (!isNumber(tipo1) && !isNumber(tipo2)){
                typeerror();
                YYABORT;
            }

            // $$->type = TYPE_BOOL; 
            printf("simple_expr RELOP (%s) simple_expr\n", $2);
            intmdt_addr_t *temp = newtemp(TYPE_BOOL);
            temp->list = malloc(sizeof(boolean_list_t));
            if (temp->list == NULL) {
                fprintf(stderr, "Malloc of boolean_list_t failed! (RELOP)\n");
                YYABORT;
            }
            gen(intermediate_code, $2, $1, $3, temp);
            temp->list->truelist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
            gen(intermediate_code, "gotoRG", NULL, NULL, NULL);
            temp->list->falselist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
            $$ = temp;
            // TODO: criar quádrupla para calcular valor
            // $$->value = $1->value; 
        }else{
            printf("Lexema RELOP não encontrado\n");
            YYABORT;
        }
    }
                        ;
simple_expr             :   term
    { 
        $$ = $1;
    }
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
                    // Dois inteiros
                    printf("simple_expr -> simple_expr + term (int,int)\n");
       	     		intmdt_addr_t *temp = newtemp(TYPE_INT);
                    gen(intermediate_code, "+", $1, $3, temp);
                    $$ = temp;
                }else{
                    // Pelo menos um real
                    printf("simple_expr -> simple_expr + term (real)\n");
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
        if (strcmp($2,"or") == 0){
            // Se algum for temporário, procure na tabela seu tipo de verdade
            int tipo1 = $1->type;
            int tipo2 = $4->type;
            tempTipo(&tipo1, &tipo2, $1, $4);
            
            // Verificação de Tipos + Geração da Quádrupla
            if (tipo1 == TYPE_BOOL && tipo2 == TYPE_BOOL){
                // printf("simple_expr -> simple_expr or term\n");
                // intmdt_addr_t *temp = newtemp(TYPE_BOOL);
                // printf("TODO: truelist e falselist\n");
                // gen(intermediate_code, "or", $1, $4, temp);
                // $$ = temp;
                printf("simple_expr -> simple_expr or term\n");

                // Remendo do primeiro do false com o valor do M
                backpatch($1->list->falselist, intermediate_code->code[$3]);
                intmdt_addr_t *temp = newtemp(TYPE_BOOL);
                // gen(intermediate_code, "or", $1, $4, temp);

                // E.falselist = E2.falselist
                temp->list = malloc(sizeof(boolean_list_t));
                if (temp->list == NULL) {
                    fprintf(stderr, "Malloc of boolean_list_t failed! (OR)\n");
                    YYABORT;
                }
                temp->list->falselist = $4->list->falselist;

                // E.truelist = merge(E1.truelist, E2.truelist)
                temp->list->truelist = list_merge($1->list->truelist,
                                                  $4->list->truelist);
                $$ = temp;
            }else{
                typeerror();
                YYABORT;
            }
        }else{
            printf("Lexema OR não encontrado: %s\n", $2);
            yyerror("");
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
                // Dois inteiros
                printf("simple_expr -> simple_expr - term (int,int)\n");
                intmdt_addr_t *temp = newtemp(TYPE_INT);
                gen(intermediate_code, "-", $1, $3, temp);
                $$ = temp;
            }else{
                // Pelo menos um real
                printf("simple_expr -> simple_expr - term (real)\n");
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
term                    :   factor_a
    { 
        printf("term -> factor_a\n");
        $$ = $1; 
    } 
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
                    // Dois inteiros
                    printf("term -> term * factor_a (int,int)\n");
                    intmdt_addr_t *temp = newtemp(TYPE_INT);
                    gen(intermediate_code, "*", $1, $3, temp);
                    $$ = temp;
                }else{
                    // Pelo menos um real
                    printf("term -> term * factor_a (real)\n");
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
                printf("term -> term / factor_a (real)\n");
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
                printf("term -> term div factor_a (int,int)\n");
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
                printf("term -> term mod factor_a (int,int)\n");
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
        if (strcmp($2,"and") == 0){
            // Se algum for temporário, procure na tabela seu tipo de verdade
            int tipo1 = $1->type;
            int tipo2 = $4->type;
            tempTipo(&tipo1, &tipo2, $1, $4);
            
            // Verificação de Tipos + Geração da Quádrupla
            if (tipo1 == TYPE_BOOL && tipo2 == TYPE_BOOL){
                // printf("term -> term and factor_a\n");
                // intmdt_addr_t *temp = newtemp(TYPE_BOOL);
                // printf("TODO: truelist e falselist\n");
                // gen(intermediate_code, "and", $1, $3, temp);
                // $$ = temp;

                printf("term -> term and factor_a\n");

                // Remendo do primeiro do true com o valor do M
                backpatch($1->list->truelist, intermediate_code->code[$3]);
                intmdt_addr_t *temp = newtemp(TYPE_BOOL);
                // gen(intermediate_code, "&&", $1, $4, temp);

                // E.truelist = E2.truelist
                temp->list = malloc(sizeof(boolean_list_t));
                if (temp->list == NULL) {
                    fprintf(stderr, "Malloc of boolean_list_t failed! (AND)\n");
                    YYABORT;
                }
                temp->list->truelist = $4->list->truelist;

                // E.falselist = merge(E1.falselist, E2.falselist)
                temp->list->falselist = list_merge($1->list->falselist,
                                                   $4->list->falselist);
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
function_ref            :   IDENTIFIER_F '(' expr_list ')'
    {
        // Tratamento Quantidade de Argumentos
        printf("Tratando Argumentos\n");
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
                && (strcmp($1,"eof") == 0)
            )){
            // Eof e Eoln devem ser invocadas sem argumento
            sprintf(buf, "Muitos argumentos para %s\n", $1);
            yyerror(buf);
            YYABORT;
        }
        
        printf("Tratando Temporários\n");
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

        printf("Gerando Código\n");
        // Verificação de Tipos + Geração da Quádrupla
        if (isNumToReal($1)){
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

        }else if (strcmp($1,"eoln") == 0 || strcmp($1,"eof") == 0){
            // Verifica EOLn na entrada padrão
            // Não há tipos a verificar

            // Temporário para resultado + gerência de truelist/falselist
            intmdt_addr_t *temp = newtemp(TYPE_BOOL);
            temp->list = malloc(sizeof(boolean_list_t));
            if (temp->list == NULL) {
                fprintf(stderr, "Malloc of boolean_list_t failed! (funct)\n");
                YYABORT;
            }

            gen(intermediate_code, $1 , NULL, NULL, temp);
            temp->list->truelist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
            gen(intermediate_code, "gotoF", NULL, NULL, NULL);
            temp->list->falselist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
            $$ = temp;

        }else{
            printf("Função não encontrada: %s\n", $1);
            yyerror("");
            YYABORT;
        }
    }
                        |   IDENTIFIER_F
    {
        if (strcmp($1,"eoln") == 0 || strcmp($1,"eof") == 0){
            // Verifica EOLn na entrada padrão
            // Não há tipos a verificar

            // Temporário para resultado + gerência de truelist/falselist
            intmdt_addr_t *temp = newtemp(TYPE_BOOL);
            temp->list = malloc(sizeof(boolean_list_t));
            if (temp->list == NULL) {
                fprintf(stderr, "Malloc of boolean_list_t failed! (funct)\n");
                YYABORT;
            }

            gen(intermediate_code, $1 , NULL, NULL, temp);
            temp->list->truelist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
            gen(intermediate_code, "gotoF", NULL, NULL, NULL);
            temp->list->falselist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
            $$ = temp;
        }else{
            printf("Função não encontrada: %s\n", $1);
            yyerror("");
            YYABORT;
        }
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
        printf("factor_a -> - factor \n");
        intmdt_addr_t *temp;
        if (tipo1 == TYPE_INT){
            temp = newtemp(TYPE_INT);
        }else if (tipo1 == TYPE_REAL){
            temp = newtemp(TYPE_INT);
        }else{
            typeerror();
            YYABORT;
        }

        // Geração da Quádrupla
        gen(intermediate_code, "1-", $2, NULL, temp);
        $$ = temp;
    }                      
                        |   factor
    { 
        printf("factor_a -> factor\n");
        $$ = $1;
    }
                        ;
factor                  :   IDENTIFIER
    { 
        printf("factor -> id(1)\n");
        // Pesquisa a entrada na tabela de símbolos
        int res_niv;
        int res_i;
        Get_Entry($1, &res_niv, &res_i);
        if (res_niv == -1){
            // Não encontrou na tabela
            exit(1);
        }

        printf("factor -> id(2)\n");
        intmdt_addr_t *dest = malloc (sizeof(intmdt_code_t));
        if (dest == NULL) {
            fprintf(stderr,"Error: could not malloc dest in 'factor -> identifier'");
            YYABORT;
        }
        printf("factor -> id(3)\n");
        dest->type = TS_ENTRY;
        dest->value.TS_idx = res_i;

        printf("factor -> id(4)\n");
        TabelaS[res_i].class = CLS_VARIABLE;
        boolean_list_t *list = NULL;
        if (TabelaS[res_i].type == TYPE_BOOL){
            printf("factor -> id(5)\n");
            intmdt_addr_t *temp = newtemp(TYPE_BOOL);
            temp->list = malloc(sizeof(boolean_list_t));
            if (temp->list == NULL) {
                fprintf(stderr, "Malloc of boolean_list_t failed! (factor -> id)\n");
                exit(1);
            }
            gen(intermediate_code, "boolV", dest, NULL, temp);    // if id goto __
            temp->list->truelist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
            gen(intermediate_code, "gotoB", NULL, NULL, NULL);   // else goto ___
            temp->list->falselist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
            $$ = temp;
        }else{
            printf("factor -> id\n");
            $$ = dest;
        }
    }
                        |   constant
                            { 
                                $$ = $1; 
                            }
                        |   '(' expr ')'
                            { 
                                $$ = $2; 
                            }
                        |   function_ref
                            { 
                                // TODO: tipo função 
                                //       + verificação tipos parâmtros
                                //       + verificaçaõ tipo retorno
                                $$ = $1;
                            }
                        |   NOT factor
    { 
        // Basta inverter as listas
        printf("factor -> NOT factor\n");
        intmdt_addr_t *temp = newtemp(TYPE_BOOL);
        temp->list = malloc(sizeof(boolean_list_t));
        if (temp->list == NULL) {
            fprintf(stderr, "Malloc of boolean_list_t failed! (NOT)\n");
            YYABORT;
        }

        int tipo1 = $2->type;
        if (tipo1 == TS_ENTRY){
            int idx = $2->value.TS_idx;
            tipo1 = TabelaS[idx].type;
        }

        if (tipo1 != TYPE_BOOL){
            typeerror();
            YYABORT;
        }
        temp->list->truelist = $2->list->falselist;
        temp->list->falselist = $2->list->truelist;
        $$ = temp;
      
        // // Se algum for temporário, procure na tabela seu tipo de verdade
        // int tipo1 = $2->type;
        // if (tipo1 == TS_ENTRY){
        //     int idx = $2->value.TS_idx;
        //     tipo1 = TabelaS[idx].type;
        // }
        
        // // Verificação de Tipos                         
        // if (tipo1 != TYPE_BOOL){
        //     typeerror();
        //     YYABORT;
        // }

        // // Geração da Quádrupla
        // printf("factor -> NOT factor\n");
        // intmdt_addr_t *temp = newtemp(TYPE_BOOL);
        // printf("TODO: truelist e falselist\n");
        // gen(intermediate_code, "NOT", $2, NULL, temp);
        // $$ = temp;
    }
                        ;
constant                :   INT_CONSTANT            
                            {
                                intmdt_addr_t *temp = newtemp(TYPE_INT);
                                TabelaS[temp->value.TS_idx].class = CLS_CST;
                                TabelaS[temp->value.TS_idx].value.integer = $1;
                                $$ = temp;
                                $$->list = NULL;
                                
                                intmdt_addr_print($$);
                                printf("\n");
                            }
                        |   REAL_CONSTANT
                            { 
                                intmdt_addr_t *temp = newtemp(TYPE_REAL);
                                TabelaS[temp->value.TS_idx].class = CLS_CST;
                                TabelaS[temp->value.TS_idx].value.real = $1;
                                $$ = temp;
                                $$->list = NULL;
                                
                                intmdt_addr_print($$);
                                printf("\n");
                            }
                        |   CHAR_CONSTANT
                            { 
                                intmdt_addr_t *temp = newtemp(TYPE_CHAR);
                                TabelaS[temp->value.TS_idx].class = CLS_CST;
                                TabelaS[temp->value.TS_idx].value.character = $1;
                                $$ = temp;
                                $$->list = NULL;

                                intmdt_addr_print($$);
                                printf("\n");
                            }
                        |   TRUE_CST
    { 
        intmdt_addr_t *temp = newtemp(TYPE_BOOL);
        TabelaS[temp->value.TS_idx].class = CLS_CST;
        TabelaS[temp->value.TS_idx].value.boolean = $1;
        // $$ = temp;

        printf("constant -> true\n");
        temp->list = malloc(sizeof(boolean_list_t));
        if (temp->list == NULL) {
            fprintf(stderr, "Malloc of boolean_list_t failed!\n");
            YYABORT;
        }
        /* Generate a goto statement with no destination,
            then pass it into a list for backpatching. */

        gen(intermediate_code, "gotoT", NULL, NULL, NULL);
        quadruple_t* quad = intermediate_code->code[intermediate_code->n - 1];
        printQuad(quad, quad->n);
        temp->list->truelist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);

        temp->list->falselist = NULL;

        $$ = temp;
        printf("constant -> true 3\n");


        intmdt_addr_print($$);
        printf("\n");
    }                   |   FALSE_CST
    { 
        intmdt_addr_t *temp = newtemp(TYPE_BOOL);
        TabelaS[temp->value.TS_idx].class = CLS_CST;
        TabelaS[temp->value.TS_idx].value.boolean = $1;
        // $$ = temp;
        
        printf("constant -> false\n");
        boolean_list_t *list = malloc(sizeof(boolean_list_t));
        if (list == NULL) {
            fprintf(stderr, "Malloc of boolean_list_t failed!\n");
            YYABORT;
        }
        /* Generate a goto statement with no destination,
            then pass it into a list for backpatching. */
        gen(intermediate_code, "gotoF", NULL, NULL, NULL);
        list->truelist = NULL;
        list->falselist = list_makelist(intermediate_code->code[intermediate_code->n - 1]);
        $$->list = list;

        intmdt_addr_print($$);
        printf("\n");
    }
                        ;


%%                     

/*
Instala a lista de identificadores 'id_list' (global) de tipo 'type' na 
tabela de símbolos
*/
void installIdentList(char* type){
    //   Obs.: o tamanho do array 'id_list' está na variável global 'q'
    int i = 0;
    // printf("%i declaracoes do tipo %s\n", q, type);

    for (i = 0; i < q; i++){
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
        Instala(id_list[i], tipo_cst, cls, placeholder, blist);
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
        /* imprimir();     // Imprime a tabela de símbolos ao final */
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