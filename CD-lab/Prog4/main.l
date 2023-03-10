%{
	#include<stdio.h>
	
	int vow_count=0;
	int const_count =0;
%}

%%
[aeiouAEIOU] {vow_count++;}
[a-zA-Z] {const_count++;}
%%
int yywrap(){}
int main(int argc, char** argv)
{
  yyin = fopen(argv[1], "r");
	if (!yyin) {
		printf("Error opening file: %s\n", argv[1]);
		return 1;
	}
	yylex();
	printf("Number of vowels are: %d\n", vow_count);
	printf("Number of consonants are: %d\n", const_count);
	return 0;
}
