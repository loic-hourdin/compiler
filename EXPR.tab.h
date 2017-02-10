/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_EXPR_TAB_H_INCLUDED
# define YY_YY_EXPR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TEXSCI_BEGIN = 258,
    TEXSCI_END = 259,
    BLANKLINE = 260,
    MULT = 261,
    ID = 262,
    INT = 263,
    STRING = 264,
    IN = 265,
    INTEGER = 266,
    LOCAL = 267,
    PLUS = 268,
    MINUS = 269,
    IF = 270,
    EIF = 271,
    WHILE = 272,
    FOR = 273,
    TO = 274,
    TCC = 275,
    NON = 276,
    ET = 277,
    OU = 278,
    PLUSGRAND = 279,
    PLUSPETIT = 280,
    PLUSGRANDEG = 281,
    PLUSPETITEG = 282,
    NONEG = 283,
    LEFTARROW = 284,
    MBOX = 285,
    PRINT = 286,
    PRINTTEXT = 287,
    PRINTLN = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "EXPR.y" /* yacc.c:1909  */

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

#line 106 "EXPR.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_EXPR_TAB_H_INCLUDED  */
