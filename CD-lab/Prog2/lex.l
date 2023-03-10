%{

	#include<stdio.h>


%}

%%

auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|continue|for|signed|void|do|if|static|while|default|goto|sizeof|volatile|const|float|short     {printf("KEYWORD\n");} 					
"+"|"-"|"*"|"/"|"%"|">"|"<"|"="|">="|"<="|"&&"|"||"|"==" {printf("OPERATOR\n");}
([a-zA-Z][0-9])+|[a-zA-Z]* {printf("SYMBOL\n");}    
.|\n ;

%%

int yywrap(void){}

int main(){
	yylex();
	return 0;
}
