
%{

#include "EXPRc.h"

int yydebug=1; 

extern void yyerror(const char * s);
extern int yylex();

%}

%union {
	int intval;
	name_t strval;
	char* stringval;
	struct {
		struct symbol * ptr;
		struct code * code;
		int index;
	} exprval;
	struct {
		struct code * code;
	} code;
  struct {
    struct code * true;
    struct code * false;
  } cond;
}

%token TEXSCI_BEGIN TEXSCI_END BLANKLINE MULT
%token <strval> ID
%token <intval> INT
%token <stringval> STRING
%token IN INTEGER
%token LOCAL
%token PLUS MINUS
%token IF EIF WHILE FOR TO TCC
%token NON ET OU PLUSGRAND PLUSPETIT PLUSGRANDEG PLUSPETITEG NONEG

%token LEFTARROW MBOX PRINT PRINTTEXT PRINTLN

%type <exprval> expression identifiant
%type <code> algorithm variabledef variables
%type <code> commandes
%type <code> commande
%type <cond> conditions
%type <cond> condition


%left ET OU
%left PLUS MINUS MULT
%right NON

%%

algorithm_list
: algorithm_list algorithm
| algorithm
;

algorithm:
		TEXSCI_BEGIN '{' ID '}' variables BLANKLINE commandes TEXSCI_END
		{
			fprintf(stderr, "[texcc] info: algorithm \"%s\" parsed\n", $3);
			//free($3);
			CODE=concat_code($5.code, $7.code);
			code_free($5.code);
			code_free($7.code);
		}
	;

variables:
	  variables LOCAL '{''$' variabledef '$''}'
		{
			$$.code = concat_code($1.code, $5.code);
			code_free($1.code);
			code_free($5.code);
		}
	|
		{
			$$.code = code_new();
		}
	;
variabledef:
	  ID IN INTEGER
	  	{
	  		$$.code = code_new();
	  		struct symbol * id = symtable_put(SYMTAB,$1);
	  	}
	| variabledef','ID IN INTEGER
		{
			$$.code = $1.code;
			struct symbol * id = symtable_put(SYMTAB,$3);
		}
	| ID IN INTEGER '^' '{' INT '}' 
		{
			$$.code = code_new();
			struct symbol * id = symtable_put_list(SYMTAB,$1, $6, "INT");
		}
	| ID IN INTEGER '^' '{' INT MULT INT '}' 
		{
			char *str = malloc((strlen($1)+10)*sizeof(char));

			$$.code = code_new();
			symtable_put_list(SYMTAB,$1, $6*$8, "INT");

			strcpy(str, $1);
			strcat(str, "_h");
			struct symbol * id = symtable_put_list_dim(SYMTAB,str);
			gencode($$.code,COPY,id,symtable_const(SYMTAB,$6),NULL);

			strcpy(str, $1);
			strcat(str, "_w");
			id = symtable_put_list_dim(SYMTAB,str);
			gencode($$.code,COPY,id,symtable_const(SYMTAB,$8),NULL);

			free(str);
		}
	;

commandes:
	  commande commandes			{ $$.code = concat_code($1.code,$2.code);code_free($1.code);code_free($2.code); }
	|								{ $$.code=code_new(); }
	;

identifiant:
	  '$' ID LEFTARROW expression'$'
		{
			$$.code = $4.code;
			struct symbol * id = symtable_get(SYMTAB,$2);
			if ( id == NULL )
			{
				fprintf(stderr,"::error::Name '%s' undeclared\n",$2);
				exit(3);
			}
			gencode($$.code,COPY,id,$4.ptr,NULL);
			$$.ptr = id;
		}
	| '$' ID '_' '{' expression '}' LEFTARROW expression'$'
		{
			$$.code = concat_code($5.code, $8.code);
			code_free($5.code);
			code_free($8.code);

			struct symbol * list = symtable_get(SYMTAB,$2);
			if ( list == NULL )
			{
				fprintf(stderr,"::error::Name '%s' undeclared\n",$2);
				exit(3);
			}
			gencode($$.code,LIST_SET,list,symtable_const(SYMTAB,$5.ptr->u.value),$8.ptr);
			
			$$.ptr = list;
			$$.index = $5.ptr->u.value;
		}
	| '$' ID '_' '{' expression ',' expression '}' LEFTARROW expression'$'
		{
			char *str = malloc((strlen($2)+10)*sizeof(char));
			struct symbol *tmp = newtemp(SYMTAB);

			$$.code = concat_code($5.code, $7.code);
			code_free($5.code);
			code_free($7.code);

			struct code * tmp_code =$$.code;
			$$.code = concat_code($$.code, $10.code);
			code_free(tmp_code);
			code_free($10.code);

			struct symbol * list = symtable_get(SYMTAB,$2);
			if ( list == NULL )
			{
				fprintf(stderr,"::error::Name '%s' undeclared\n",$2);
				exit(1);
			}

			strcpy(str, $2);
			strcat(str, "_h");

			struct symbol * height = symtable_get(SYMTAB,str);
			gencode($$.code,BOP_MULT,tmp,$5.ptr,height);
			gencode($$.code,BOP_PLUS,tmp,tmp,$7.ptr);
			gencode($$.code,LIST_SET,list,tmp,$10.ptr);
			
			$$.ptr = list;
			$$.index = tmp->u.value;
			free(str);
		}
	| ID
		{
			$$.code = code_new();
			struct symbol * id = symtable_get(SYMTAB,$1);
			if ( id == NULL )
			{
				fprintf(stderr,"::error::Name '%s' undeclared\n",$1);
				exit(3);
			}
			$$.ptr = id;
		}
	| ID '_' '{' expression '}'
		{
			$$.code = $4.code;

			struct symbol * list = symtable_get(SYMTAB,$1);
			if ( list == NULL )
			{
				fprintf(stderr,"::error::Name '%s' undeclared\n",$1);
				exit(3);
			}
			
			$$.ptr = list;
			$$.index = $4.ptr->u.value;
		}
	| ID '_' '{' expression ',' expression '}'
		{
			char *str = malloc((strlen($1)+10)*sizeof(char));
			struct symbol *tmp = newtemp(SYMTAB);

			$$.code = concat_code($4.code, $6.code);
			code_free($4.code);
			code_free($6.code);

			struct symbol * list = symtable_get(SYMTAB,$1);
			if ( list == NULL )
			{
				fprintf(stderr,"::error::Name '%s' undeclared\n",$1);
				exit(1);
			}

			strcpy(str, $1);
			strcat(str, "_h");

			struct symbol * height = symtable_get(SYMTAB,str);
			gencode($$.code,BOP_MULT,tmp,$4.ptr,height);
			gencode($$.code,BOP_PLUS,tmp,tmp,$6.ptr);
			
			$$.ptr = list;
			$$.index = tmp->u.value;

			free(str);
		}
	;

commande:
	  identifiant '\\'';'
		{
			$$.code = $1.code;
		}
	|'$' MBOX '{'PRINT'(''$'expression'$'')' '}''$''\\'';'
		{
			$$.code = $7.code;
			gencode($$.code,CALL_PRINT,$7.ptr,NULL,NULL);
		}
	|'$' MBOX '{'PRINTTEXT'(''$'STRING'$'')' '}''$''\\'';'
		{
			$$.code = code_new();
			struct symbol * id = symtable_put_string(SYMTAB,$7);
			gencode($$.code,CALL_PRINT_STRING,id,NULL,NULL);
		}
	|'$' MBOX '{'PRINTLN'('')' '}''$''\\'';'
		{
			$$.code = code_new();
			gencode($$.code,CALL_PRINT_LN,NULL,NULL,NULL);
		}
	| TCC
		{
			$$.code = code_new();
		}
	| IF '{' '$' conditions '$' '}' '{' commandes '}'
		{
			struct symbol * out = newlabel(SYMTAB);
			code_replace_unknow_label($4.true,out);
			$$.code = concat_code($4.true,$8.code);
			gencode($$.code,SET_LABEL,out,NULL,NULL);
			code_free($4.true);code_free($4.false);
			code_free($8.code);
		}
	| EIF '{' '$' conditions '$' '}' '{' commandes '}' '{' commandes '}'
		{
			struct symbol *label_else = newlabel(SYMTAB);
			struct symbol *out = newlabel(SYMTAB);

			gencode($8.code,GOTO,out,NULL,NULL);
			gencode($8.code,SET_LABEL,label_else,NULL,NULL);
			code_replace_unknow_label($4.true,label_else);

			$$.code = concat_code($4.true,$8.code);
			struct code * tmp_code =$$.code;
			$$.code = concat_code($$.code, $11.code);
			code_free(tmp_code);
			gencode($$.code,SET_LABEL,out,NULL,NULL);
			code_free($4.true);code_free($4.false);
		}
	| WHILE '{' '$' conditions '$' '}' '{' commandes '}'
		{
			$$.code = code_new();
			struct symbol *label_while = newlabel(SYMTAB);
			gencode($$.code,SET_LABEL,label_while,NULL,NULL);

			struct symbol * out = newlabel(SYMTAB);
			code_replace_unknow_label($4.true,out);
			gencode($8.code,GOTO,label_while,NULL,NULL);
			struct code * tmp_code =$$.code;
			$$.code = concat_code($$.code,$4.true);
			code_free(tmp_code);
			tmp_code =$$.code;
			$$.code = concat_code($$.code,$8.code);
			code_free(tmp_code);
			gencode($$.code,SET_LABEL,out,NULL,NULL);
			code_free($4.true);code_free($4.false);
			code_free($8.code);
		}
	| FOR '{' identifiant TO '$' expression '$' '}' '{' commandes '}'
		{
			struct symbol *tmp;
			struct symbol *label_for = newlabel(SYMTAB);
			struct symbol *label_out = newlabel(SYMTAB);

			if($3.ptr->kind == LIST) {
				tmp = newtemp(SYMTAB);
			}

			$$.code = $3.code;
			gencode($$.code,SET_LABEL,label_for,NULL,NULL);

			if($3.ptr->kind == LIST) {
				gencode($10.code,LIST_GET,tmp,$3.ptr,symtable_const(SYMTAB,$3.index));
				// Egalité
				gencode($10.code, TEST_EGALITE, label_out, tmp, $6.ptr);
				// Affection
				gencode($10.code, BOP_PLUS, tmp, tmp, symtable_const(SYMTAB, 1));
				gencode($10.code,LIST_SET,$3.ptr,symtable_const(SYMTAB,$3.index),tmp);
			}
			else {
				// Egalité
				gencode($10.code, TEST_EGALITE, label_out, $3.ptr, $6.ptr);
				// Affection
				gencode($10.code, BOP_PLUS, $3.ptr, $3.ptr, symtable_const(SYMTAB, 1));
			}

			gencode($10.code,GOTO,label_for,NULL,NULL);
			gencode($10.code,SET_LABEL,label_out,NULL,NULL);
			struct code * tmp_code =$$.code;
			$$.code = concat_code($$.code, $10.code);
			code_free($10.code);code_free(tmp_code);
		}
	;

expression:
	  INT
		{
			$$.ptr = symtable_const(SYMTAB,$1);
			$$.code = code_new();
		}
	| identifiant
		{
			if($$.ptr->kind == LIST) {
				$$.ptr = newtemp(SYMTAB);
				gencode($$.code,LIST_GET,$$.ptr,$1.ptr,symtable_const(SYMTAB,$1.index));
			}
			else
				$$.ptr = $1.ptr;

			$$.code = $1.code;
		}
	| expression PLUS expression
		{
			$$.ptr = newtemp(SYMTAB);

			$$.code = concat_code($1.code,$3.code);
			code_free($1.code);
			code_free($3.code); 

			gencode($$.code,BOP_PLUS,$$.ptr,$1.ptr,$3.ptr);
		}
	| expression MINUS expression
		{ 
			$$.ptr = newtemp(SYMTAB);

			$$.code = concat_code($1.code,$3.code);
			code_free($1.code);
			code_free($3.code); 

			gencode($$.code,BOP_MINUS,$$.ptr,$1.ptr,$3.ptr);
		}
	| MINUS expression
		{ 
			$$.ptr = symtable_const(SYMTAB,-1 * $2.ptr->u.value);
			$$.code = $2.code;
		}
	| expression MULT expression
		{ 
			$$.ptr = newtemp(SYMTAB);

			$$.code = concat_code($1.code,$3.code);
			code_free($1.code);
			code_free($3.code); 

			gencode($$.code,BOP_MULT,$$.ptr,$1.ptr,$3.ptr);
		}
	| '(' expression ')'
		{ 
			$$.ptr = $2.ptr;
			$$.code = $2.code;
		}
	;

conditions:
	  condition						{ $$.true = $1.true;$$.false = $1.false; }
	| '(' conditions ')'			{ $$.true = $2.true;$$.false = $2.false; }
	| NON conditions				{ $$.true = $2.false;$$.false = $2.true; }
	| conditions ET conditions		
		{
			$$.true = concat_code($1.true,$3.true);
			struct symbol * out = newlabel(SYMTAB);
			$$.false = concat_code($1.true,$3.false);
			code_replace_unknow_label($1.true,out);
			gencode($$.false,SET_LABEL,out,NULL,NULL);
			code_free($3.true);code_free($3.false);
			code_free($1.true);code_free($1.false);
		}
	| conditions OU conditions
		{
			$$.false = concat_code($1.false,$3.false);
			struct symbol * out = newlabel(SYMTAB);
			code_replace_unknow_label($1.false,out);
			$$.true = concat_code($1.false,$3.true);
			gencode($$.true,SET_LABEL,out,NULL,NULL);
			code_free($3.true);code_free($3.false);
			code_free($1.true);code_free($1.false);
		}
	;


condition:
	  expression
		{
			$$.false = code_new();
			$$.false = concat_code($$.false,$1.code);
			gencode($$.false,TEST_VAR,label_unknown(),$1.ptr,NULL);
			$$.true =$1.code;
			gencode($$.true,TEST_NON_VAR,label_unknown(),$1.ptr,NULL);
		}
	| expression '=' expression
		{
			$$.true = concat_code($1.code,$3.code);
			gencode($$.true,TEST_NON_EGALITE,label_unknown(),$1.ptr,$3.ptr);
			$$.false = concat_code($1.code,$3.code);
			gencode($$.false,TEST_EGALITE,label_unknown(),$1.ptr,$3.ptr);
			code_free($1.code);
			code_free($3.code);
		}
  | expression NONEG expression
    {
      $$.true = concat_code($1.code,$3.code);
      gencode($$.true,TEST_EGALITE,label_unknown(),$1.ptr,$3.ptr);
      $$.false = concat_code($1.code,$3.code);
      gencode($$.false,TEST_NON_EGALITE,label_unknown(),$1.ptr,$3.ptr);
      code_free($1.code);
      code_free($3.code);
    }
	| expression PLUSGRAND expression
		{
			$$.true = concat_code($1.code,$3.code);
			gencode($$.true,TEST_LESS_OR_EQ,label_unknown(),$1.ptr,$3.ptr);
			$$.false = concat_code($1.code,$3.code);
			gencode($$.false,TEST_GREATER,label_unknown(),$1.ptr,$3.ptr);
			code_free($1.code);
			code_free($3.code);
		}
	| expression PLUSPETIT expression
		{
			$$.true = concat_code($1.code,$3.code);
			gencode($$.true,TEST_GREATER_OR_EQ,label_unknown(),$1.ptr,$3.ptr);
			$$.false = concat_code($1.code,$3.code);
			gencode($$.false,TEST_LESS,label_unknown(),$1.ptr,$3.ptr);
			code_free($1.code);
			code_free($3.code);
		}
	| expression PLUSGRANDEG expression
		{
			$$.true = concat_code($1.code,$3.code);
			gencode($$.true,TEST_LESS,label_unknown(),$1.ptr,$3.ptr);
			$$.false = concat_code($1.code,$3.code);
			gencode($$.false,TEST_GREATER_OR_EQ,label_unknown(),$1.ptr,$3.ptr);
			code_free($1.code);
			code_free($3.code);
		}
	| expression PLUSPETITEG expression
		{
			$$.true = concat_code($1.code,$3.code);
			gencode($$.true,TEST_GREATER,label_unknown(),$1.ptr,$3.ptr);
			$$.false = concat_code($1.code,$3.code);
			gencode($$.false,TEST_LESS_OR_EQ,label_unknown(),$1.ptr,$3.ptr);
			code_free($1.code);
			code_free($3.code);
		}
	;

%%

void yyerror(const char * s)
{
	fprintf(stderr,"erreur de syntaxe:%s\n",s);exit(2);
}

