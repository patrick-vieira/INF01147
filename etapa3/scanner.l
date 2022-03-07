
%{

  #include "hash.h"
  #include "ast.h"
  #include "y.tab.h"

  int running = 1;
  int lineNumber = 1;

  char buf[100]; 
  char *s;



%}

%x COMMENT
%x STRING

%%
char                        { return KW_CHAR; }
int                         { return KW_INT; }
float                       { return KW_FLOAT; }

if                          { return KW_IF; }
then                        { return KW_THEN; }
else                        { return KW_ELSE; }
while                       { return KW_WHILE; }
goto                        { return KW_GOTO; }
read                        { return KW_READ; }
print                       { return KW_PRINT; }
return                      { return KW_RETURN; }

"<="                        { yylval.symbol = hashInsert(yytext, OPERATOR_LTE); return OPERATOR_LTE; }
">="                        { yylval.symbol = hashInsert(yytext, OPERATOR_GTE); return OPERATOR_GTE; }
"=="                        { yylval.symbol = hashInsert(yytext, OPERATOR_EQ); return OPERATOR_EQ; }
"!="                        { yylval.symbol = hashInsert(yytext, OPERATOR_DIF); return OPERATOR_DIF; }

"<"                         { yylval.symbol = hashInsert(yytext, OPERATOR_LT); return OPERATOR_LT; }
">"                         { yylval.symbol = hashInsert(yytext, OPERATOR_GT); return OPERATOR_GT; }
 
"+"                         { yylval.symbol = hashInsert(yytext, OPERATOR_ADD); return OPERATOR_ADD; }
"-"                         { yylval.symbol = hashInsert(yytext, OPERATOR_SUB); return OPERATOR_SUB; }
"*"                         { yylval.symbol = hashInsert(yytext, OPERATOR_MULT); return OPERATOR_MULT; }
"/"                         { yylval.symbol = hashInsert(yytext, OPERATOR_DIV); return OPERATOR_DIV; }

[=,;:\(\)\[\]{}]             { return yytext[0]; }

[0-9]+                      { yylval.symbol = hashInsert(yytext, LIT_INTEGER); return LIT_INTEGER; }
'.'                         { yylval.symbol = hashInsert(yytext, LIT_CHAR); return LIT_CHAR; }
[-_a-z]+                    { yylval.symbol = hashInsert(yytext, TK_IDENTIFIER); return TK_IDENTIFIER; }


\"                { BEGIN(STRING); s = buf; } 
<STRING>\\n       { *s++ = '\\'; *s++ = 'n'; } 
<STRING>\\t       { *s++ = '\\'; *s++ = 't'; } 
<STRING>\\\"      { *s++ = '\\'; *s++ = '\"'; } 
<STRING>\"        { 
                    *s = 0; 
                    BEGIN(INITIAL);               
                    yylval.symbol = hashInsert(buf, LIT_STRING);      
                    // printf("found '%s'\n", buf);
                    return LIT_STRING;
                  } 
<STRING>\n        { 
                    *s = 0; 
                    lineNumber++;
                    BEGIN 0;
                    return TOKEN_ERROR; 
                  } 
<STRING>.         { *s++ = *yytext; } 



"\\\\".*
"\\*"                     { BEGIN(COMMENT); }
<COMMENT>"*\\"            { BEGIN(INITIAL); }
<COMMENT>[\n]             { lineNumber++; }
<COMMENT>.

[ \t]
[\n]                        { lineNumber++; }
.                           { return TOKEN_ERROR; }

%%


int isRunning() {
  return running;
}

int getLineNumber(void) {
  return lineNumber;
}

void initMe() {
  hashInit();
}

int yywrap() {
  running = 0;
  return 1;
}

