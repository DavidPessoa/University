%{
	#include "tacl.tab.h"
	
%}

%option noinput
%option nounput
%option yylineno

%%


"["     {return PARRE;} 
"]"     {return PARRD;}
"("		{return PARE;}
")"	    {return PARD;}
","		{return COMMA;}
";"		{return SEMICOLON;}
":"		{return TWODOT;}
"."		{return DOT;}
"id"    {return ID;}
"var"   {return VAR;}
"local"	{return LOCAL;}
"arg"	{return ARG;}
"fun"   {return FUN;}
"body"  {return BODY;}
"call"  {return CALL;}
"print" {return PRINT;}
"if"	{return IF;}
"while" {return WHILE;}
"or"	{return OR;}
"and" 	{return AND;}
"assign" {return ASSIGN;}
"ne" 	{return NE;}
"lt" 	{return LT;}
"le" 	{return LE;}
"gt" 	{return GT;}
"ge" 	{return GE;}
"plus" 	{return PLUS;}
"minus" {return MINUS;}
"times" {return TIMES;}
"div" 	{return DIV;}
"mod" 	{return MOD;}
"not" 	{return NOT;}
"inv" 	{return INV;}
"int_literal" 	{return INT_LITERAL;}
"real_literal" 	{return REAL_LITERAL;}
"true" 	{return TRUE;}
"false" {return FALSE;}
"toreal" {return TOREAL;}
"int" 	{return INT;} 
"real" 	{return REAL;}
"bool" 	{return BOOL;} 
"nil"   {return NIL;}
"eq"  	{return EQ;}

[0-9]+   { yylval.integer = atoi(yytext); return INTEGER; }

[0-9]*\.[0-9]+([eE][\+\-]?[0-9]+)? 		{ yylval.real = atof(yytext); return REAL; }
[a-zA-Z][a-zA-Z0-9]*     { yylval.name = strdup(yytext); return NAME; }
[ \t\n,"]+  ; 
%%