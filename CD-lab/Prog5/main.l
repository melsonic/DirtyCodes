%{
#include <stdio.h>
#include <ctype.h>
int line_count = 0, word_count = 0, special_count = 0, letter_count = 0;
%}

%%
\n { line_count++; }
[a-zA-Z]+ { letter_count += strlen(yytext); word_count++; }
[[:punct:]] { special_count++; }
%%

int yywrap(void){ return 1; }

int main(int argc, char** argv) {
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }
    yylex();
    printf("Line count: %d\n", line_count);
    printf("Word count: %d\n", word_count);
    printf("Special character count: %d\n", special_count);
    printf("Letter count: %d\n", letter_count);
    return 0;
}
