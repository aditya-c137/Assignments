%{
%}

%%

public |
private |
protected {printf("\n%s Access Specifier\n", yytext);}

static  {printf("\n%s static keyword\n", yytext);}

void |
int |
float |
double |
bool |
char    {printf("\n%s data type\n",yytext);}

main    {printf("\n%s main function\n",yytext);}

System  {printf("\n%s class\n",yytext);}

out     {printf("\n%s variable\n",yytext);}

println {printf("\n%s method\n",yytext);}

%%

int yywrap(){}

int main(){

yylex();
return 0;


}
