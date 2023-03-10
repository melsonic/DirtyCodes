%{
	#include <stdio.h>
	#include <string.h>
	char store[50][500];
	int ii = 0;
%}

%%
"\n" {++ii;}
"auto"|"double"|"main"|"int"|"struct" {strcat (store[ii], "<KEYWORD> ");}
"break"|"else"|"long"|"switch"|"case"|"printf" {strcat (store[ii], "<KEYWORD> ");}
"enum"|"register"|"typedef"|"char" {strcat (store[ii], "<KEYWORD> ");}
"for"|"signed"|"void"|"do"|"if" {strcat (store[ii], "<KEYWORD> ");}
"extern"|"return"|"union"|"continue" {strcat (store[ii], "<KEYWORD> ");}
"static"|"while"|"default"|"goto" {strcat (store[ii], "<KEYWORD> ");}
"sizeof"|"volatile"|"const"|"float"|"short" {strcat (store[ii], "<KEYWORD> ");}
"#include"[ \<a-z.A-Z\>]* {strcat (store[ii], "<HEADER FILE>\n");}
[{;}] {strcat (store[ii], " <SEPARATOR>\n");}
[,()] {strcat (store[ii], " <SEPARATOR> ");}
[+-/=*%] {strcat (store[ii], "<OPERATOR> ");}
[a-zA-Z][a-zA-Z0-9_]* {strcat (store[ii], "<IDENTIFIER> ");}
[0-9]* {strcat (store[ii], "<VALUE> ");}
. {}			
%%

int yywrap() {
	return 1;
}

int main (int argc, char** argv) {
//	printf ("Give Your C Program\n");
	if(argc==2)
		yyin=fopen(argv[1],"r");
	else
	{
		printf("\nEnter the input:\n");
		yyin=stdin;
	}
	yylex();
	
	for (int i = 0; i < ii; ++i)
		printf ("%s ", store[i]);
	getchar();
	return 0;
}
