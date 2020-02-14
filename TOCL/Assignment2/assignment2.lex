%{

int lines = 0;
int chars = 0;
int spaces = 0;

%}

%%

\n      {++lines;}

[0-9a-zA-Z]     {++chars;}

" "     {++spaces;}

%%

int yywrap(){
        return 1;
}

int main(int argc, char* argv[]){
        FILE *fp;
        fp = fopen(argv[1],"r");
        yyin = fp;
        yylex();
        yywrap();
        printf("\nLines:%d\nChars:%d\nWords:%d\n",lines,chars,lines+spaces);
        return 0;
}
