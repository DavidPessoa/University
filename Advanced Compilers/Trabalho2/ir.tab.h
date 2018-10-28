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

#ifndef YY_YY_IR_TAB_H_INCLUDED
# define YY_YY_IR_TAB_H_INCLUDED
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
    NUM = 258,
    REAL = 259,
    NAME = 260,
    FUNCTION = 261,
    AT = 262,
    TEMP = 263,
    ARROW = 264,
    COMMA = 265,
    JUMP = 266,
    RETURN = 267,
    FP = 268,
    A = 269,
    G = 270,
    L = 271,
    PARRE = 272,
    PARRD = 273,
    VALUE = 274,
    LSTORE = 275,
    ASTORE = 276,
    GSTORE = 277,
    LLOAD = 278,
    ALOAD = 279,
    GLOAD = 280,
    MUL = 281,
    SUB = 282,
    ADD = 283,
    DIV = 284,
    MOD = 285,
    INV = 286,
    EQ = 287,
    LT = 288,
    ITOR = 289,
    NOT = 290,
    COPY = 291,
    CJUMP = 292,
    CALL = 293,
    I = 294,
    T = 295,
    R = 296,
    TWODOT = 297,
    PRINT = 298,
    FUN = 299,
    VOID = 300,
    ID = 301,
    INT = 302,
    VAR = 303,
    PARD = 304,
    PARE = 305,
    REALTYPE = 306,
    B = 307,
    BOOL = 308,
    TRUE = 309,
    FALSE = 310,
    NE = 311,
    LE = 312
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "ir.y" /* yacc.c:1909  */

	int num;
  char *name;
  double real;
  struct Function *function;
  struct MoreFunctions *moreFunctions;
  struct Body *body;
  struct MoreExpressions *moreExpressions;
  struct Expression *expression;
  struct Id *id;
  struct Args *args;
  struct Op *op;
  struct JLabel *jLabel;
  struct Type *type;
  struct Declaration *declaration;
  struct DeclType *declType;
  struct DeclArgs *declArgs;
  struct InitialValue *initialValue;
  struct Arguments *arguments;
  struct MoreArgDecl *moreArgDecl;
  struct MoreDeclarations *moreDeclarations;
  struct BoolVal *boolVal;


#line 137 "ir.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_IR_TAB_H_INCLUDED  */
