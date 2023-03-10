%{
#include<stdio.h>
%}

alphabet [a-zA-Z]+
%option noyywrap

%%  

{alphabet} {printf("alphabet");}
.* {printf("Not an alphabet");}

%%   


int main() {
  yylex();
  return 0;
}