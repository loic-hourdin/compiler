
%{
#include "lib.h"
#include "EXPR.tab.h"
%}

%option nounput
%option noyywrap

%s texsci

begin		"\\begin{texsci}"
end			"\\end{texsci}"
blankline	"\\BlankLine"

id			[a-zA-Z](_[a-zA-Z])*[a-zA-Z0-9]*
entier		[0-9]+
string		""\"[^\"]*"\""

print		"printInt"
printtext	"printText"
println		"println"

integer		"\\Integer"
local		"\\Local"
in			"\\in"
mult		"\\times"

eiff		"\\eIf"
iff			"\\If"

non			"\\neg"
ou			"\\vee"
et			"\\wedge"
plusgrandeg	"\\geq"
pluspetiteg	"\\leq"
noneg	"\\neq"

while		"\\While"
for			"\\For"
to 			"\\KwTo"

leftarrow	"\\leftarrow"
mbox		"\\mbox"

%%

\\tcc\{.*\}			{ return TCC; }

{begin}				{
						BEGIN(texsci);   // Start TexSci scanning mode
						return TEXSCI_BEGIN;
					}
<texsci>{end}		{
						BEGIN(INITIAL); // Reset to default scanning mode
						return TEXSCI_END;
					}
<texsci>{print}		{ return PRINT; }
<texsci>{printtext}	{ return PRINTTEXT; }
<texsci>{println}	{ return PRINTLN; }

<texsci>{id}		{
						if ( yyleng > 7 )
							fprintf(stderr,"Identifier '%s' too long, truncated\n",yytext);
						strncpy(yylval.strval,yytext,7);
						yylval.strval[7] = '\0';
						return ID;
					}
<texsci>{entier}	{
						//printf("val:%d\n", atoi(yytext));
						yylval.intval = atoi(yytext);
						return INT;
					}
<texsci>{string}	{
						yylval.stringval=strdup(yytext);
						return STRING;
					}
 
<texsci>{integer}	{ return INTEGER; }
<texsci>{local}		{ return LOCAL; }

<texsci>{in}		{ return IN; }
<texsci>{mult}		{ return MULT; }

<texsci>{eiff}			{ return EIF; }
<texsci>{iff}			{ return IF; }
<texsci>{non}			{ return NON; }
<texsci>{et}			{ return ET; }
<texsci>{ou}			{ return OU; }
<texsci>{plusgrandeg}	{ return PLUSGRANDEG; }
<texsci>{pluspetiteg}	{ return PLUSPETITEG; }
<texsci>{noneg}	{ return NONEG; }
<texsci>(>=)			{ return PLUSGRANDEG; }
<texsci>(<=)			{ return PLUSPETITEG; }
<texsci>[>]				{ return PLUSGRAND; }
<texsci>[<]				{ return PLUSPETIT; }

<texsci>{while}		{ return WHILE; }
<texsci>{for}		{ return FOR; }
<texsci>{to}		{ return TO; }

<texsci>{leftarrow}	{ return LEFTARROW; }
<texsci>{mbox}		{ return MBOX; }
<texsci>{blankline}	{ return BLANKLINE; }
<texsci>[{}]		{ return yytext[0]; }
<texsci>[$]			{ return yytext[0]; }
<texsci>[\^]		{ return yytext[0]; }
<texsci>[_]			{ return yytext[0]; }
<texsci>[\\]		{ return yytext[0]; }
<texsci>[,]			{ return yytext[0]; }
<texsci>[+]			{ return PLUS; }
<texsci>[-]			{ return MINUS; }
<texsci>[;]			{ return yytext[0]; }
<texsci>[=]			{ return yytext[0]; }
<texsci>[()]		{ return yytext[0]; } 
<texsci>[.]			{ fprintf(stderr,"erreur lexical:%s\n",yytext);exit(1);}
[\n]				{ }
.					{ }

%%
