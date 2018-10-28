%{
	#include "ir.tab.h"
	
%}

%option noinput
%option nounput
%option yylineno

%%

"function"	{return FUNCTION;} 
"t"		{return T;}
"r"	    {return R;}
"<-"	{return ARROW;}
","		{return COMMA;}
"jump"	{return JUMP;}
"return" {return RETURN;}
"fp"    {return FP;}
"a"		{return A;}
"b"		{return B;}
"g"		{return G;}
"l"		{return L;}
"i"		{return I;}
"["     {return PARRE;} 
"]"     {return PARRD;}
":"		{return TWODOT;}
"(" 	{return PARE;}
")" 	{return PARD;}
"id"    {return ID;}
"fun"   {return FUN;}
"int"   {return INT;}
"real"  {return REALTYPE;}
"void"   {return VOID;}
"bool"  {return BOOL;}	
"true" 	{return TRUE;}
"false" {return FALSE;}


"value"    {return VALUE;}
"lstore"    {return LSTORE;}
"astore"    {return ASTORE;}
"gstore"    {return GSTORE;}
"lload"    {return LLOAD;}
"aload"    {return ALOAD;}
"gload"    {return GLOAD;}
"mul"    {return MUL;}
"sub"    {return SUB;}
"add"    {return ADD;}
"div"    {return DIV;}
"mod"    {return MOD;}
"inv"    {return INV;}
"eq"    {return EQ;}
"lt"    {return LT;}
"itor"    {return ITOR;}
"not"    {return NOT;}
"copy"    {return COPY;}
"cjump"	  {return CJUMP;}
"call"	  {return CALL;}
"print"	  {return PRINT;}
"var"	  {return VAR;}
"ne"	  {return NE;}
"le"	  {return LE;}

[0-9]+   { yylval.num = atoi(yytext); return NUM; }
[0-9]*\.[0-9]+([eE][\+\-]?[0-9]+)? 		{ yylval.real = atof(yytext); return REAL; }
"@"[a-zA-Z][a-zA-Z0-9]*     { yylval.name = strdup(yytext); return NAME; }

[ _\t\n"]+  ; 
%%