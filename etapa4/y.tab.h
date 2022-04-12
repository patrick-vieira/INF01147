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
    SYMBOL_FUNCTION_ARGS = 260,
    SYMBOL_VECTOR = 261,
    SYMBOL_LIT_INT = 262,
    SYMBOL_LIT_CHAR = 263,
    SYMBOL_STRING = 264,
    SYMBOL_LABEL = 265,
    SYMBOL_RETURN = 266,
    SYMBOL_EXPRESSION_BLOCK = 267,
    KW_CHAR = 268,
    KW_INT = 269,
    KW_FLOAT = 270,
    KW_IF = 271,
    KW_THEN = 272,
    KW_ELSE = 273,
    KW_WHILE = 274,
    KW_GOTO = 275,
    KW_READ = 276,
    KW_PRINT = 277,
    KW_RETURN = 278,
    OPERATOR_ADD = 279,
    OPERATOR_SUB = 280,
    OPERATOR_MULT = 281,
    OPERATOR_DIV = 282,
    OPERATOR_LTE = 283,
    OPERATOR_LT = 284,
    OPERATOR_GTE = 285,
    OPERATOR_GT = 286,
    OPERATOR_EQ = 287,
    OPERATOR_DIF = 288,
    TK_IDENTIFIER = 289,
    LIT_INTEGER = 290,
    LIT_CHAR = 291,
    LIT_STRING = 292,
    TOKEN_ERROR = 293
  };
#endif
/* Tokens.  */
#define SYMBOL_VARIABLE 258
#define SYMBOL_FUNCTION 259
#define SYMBOL_FUNCTION_ARGS 260
#define SYMBOL_VECTOR 261
#define SYMBOL_LIT_INT 262
#define SYMBOL_LIT_CHAR 263
#define SYMBOL_STRING 264
#define SYMBOL_LABEL 265
#define SYMBOL_RETURN 266
#define SYMBOL_EXPRESSION_BLOCK 267
#define KW_CHAR 268
#define KW_INT 269
#define KW_FLOAT 270
#define KW_IF 271
#define KW_THEN 272
#define KW_ELSE 273
#define KW_WHILE 274
#define KW_GOTO 275
#define KW_READ 276
#define KW_PRINT 277
#define KW_RETURN 278
#define OPERATOR_ADD 279
#define OPERATOR_SUB 280
#define OPERATOR_MULT 281
#define OPERATOR_DIV 282
#define OPERATOR_LTE 283
#define OPERATOR_LT 284
#define OPERATOR_GTE 285
#define OPERATOR_GT 286
#define OPERATOR_EQ 287
#define OPERATOR_DIF 288
#define TK_IDENTIFIER 289
#define LIT_INTEGER 290
#define LIT_CHAR 291
#define LIT_STRING 292
#define TOKEN_ERROR 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "parser.y"

    HASH_NODE *symbol;
    AST *ast;

#line 138 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
