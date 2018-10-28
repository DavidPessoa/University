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

#ifndef YY_YY_TACL_TAB_H_INCLUDED
# define YY_YY_TACL_TAB_H_INCLUDED
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
    INTEGER = 258,
    NAME = 259,
    ID = 260,
    PARRE = 261,
    PARRD = 262,
    PARE = 263,
    PARD = 264,
    COMMA = 265,
    SEMICOLON = 266,
    TWODOT = 267,
    DOT = 268,
    VAR = 269,
    LOCAL = 270,
    ARG = 271,
    FUN = 272,
    BODY = 273,
    CALL = 274,
    PRINT = 275,
    IF = 276,
    WHILE = 277,
    OR = 278,
    AND = 279,
    EQ = 280,
    NE = 281,
    LT = 282,
    LE = 283,
    GT = 284,
    GE = 285,
    PLUS = 286,
    MINUS = 287,
    TIMES = 288,
    DIV = 289,
    MOD = 290,
    NOT = 291,
    INV = 292,
    INT_LITERAL = 293,
    REAL_LITERAL = 294,
    TRUE = 295,
    FALSE = 296,
    TOREAL = 297,
    INT = 298,
    REAL = 299,
    BOOL = 300,
    ASSIGN = 301,
    NIL = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "tacl.y" /* yacc.c:1909  */

	int integer;
    double real;
    char *name;
    char *id;
    struct Gdeclpar *gdeclpar;
    struct More_Gdecl *more_gdecl;
    struct Gdecl *gdecl;
    struct Var *var;
    struct Function *function;
    struct Body *body;
    struct Formal_Arg *formal_arg;
    struct More_Formal_Arg *more_formal_arg;
    struct OP *op;
    struct Statementpar *statementpar;
    struct Statement *statement;
    struct More_Statements *more_statements;
    struct Expression2 *expression2;
    struct Expression *expression;  
    struct Expression *expression1;  
    struct More_Expressions *more_expressions;
    struct More_Decl *more_decl;
    struct Declaration *declaration;
    struct Bool_Val *bool_val;
    struct Scope *scope;
    struct Type *type;
    


#line 132 "tacl.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TACL_TAB_H_INCLUDED  */
