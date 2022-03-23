/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    SYMBOL_VARIABLE = 258,
    SYMBOL_FUNCTION = 259,
    KW_CHAR = 260,
    KW_INT = 261,
    KW_FLOAT = 262,
    KW_IF = 263,
    KW_THEN = 264,
    KW_ELSE = 265,
    KW_WHILE = 266,
    KW_GOTO = 267,
    KW_READ = 268,
    KW_PRINT = 269,
    KW_RETURN = 270,
    OPERATOR_ADD = 271,
    OPERATOR_SUB = 272,
    OPERATOR_MULT = 273,
    OPERATOR_DIV = 274,
    OPERATOR_LTE = 275,
    OPERATOR_LT = 276,
    OPERATOR_GTE = 277,
    OPERATOR_GT = 278,
    OPERATOR_EQ = 279,
    OPERATOR_DIF = 280,
    TK_IDENTIFIER = 281,
    LIT_INTEGER = 282,
    LIT_CHAR = 283,
    LIT_STRING = 284,
    TOKEN_ERROR = 285
  };
#endif
/* Tokens.  */
#define SYMBOL_VARIABLE 258
#define SYMBOL_FUNCTION 259
#define KW_CHAR 260
#define KW_INT 261
#define KW_FLOAT 262
#define KW_IF 263
#define KW_THEN 264
#define KW_ELSE 265
#define KW_WHILE 266
#define KW_GOTO 267
#define KW_READ 268
#define KW_PRINT 269
#define KW_RETURN 270
#define OPERATOR_ADD 271
#define OPERATOR_SUB 272
#define OPERATOR_MULT 273
#define OPERATOR_DIV 274
#define OPERATOR_LTE 275
#define OPERATOR_LT 276
#define OPERATOR_GTE 277
#define OPERATOR_GT 278
#define OPERATOR_EQ 279
#define OPERATOR_DIF 280
#define TK_IDENTIFIER 281
#define LIT_INTEGER 282
#define LIT_CHAR 283
#define LIT_STRING 284
#define TOKEN_ERROR 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "parser.y"

    HASH_NODE *symbol;
    AST *ast;

#line 122 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
