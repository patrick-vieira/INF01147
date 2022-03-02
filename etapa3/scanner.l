
%{

  #include "y.tab.h"
  #include "hash.h"

  int running = 1;
  int lineNumber = 1;

  char buf[100]; 
  char *s;

  void yyerror(const char *s);  
  int getLineNumber(void);  

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

"<="                        { return OPERATOR_LE; }
">="                        { return OPERATOR_GE; }
"=="                        { return OPERATOR_EQ; }
"!="                        { return OPERATOR_DIF; }

[-+*,;:\(\)\[\]{}/<>=]      { return yytext[0]; }

[0-9]+                      { hashInsert(yytext, LIT_INTEGER); return LIT_INTEGER; }
'.'                         { hashInsert(yytext, LIT_CHAR); return LIT_CHAR; }
[-_a-z]+                    { hashInsert(yytext, TK_IDENTIFIER); return TK_IDENTIFIER; }


\"                { BEGIN(STRING); s = buf; } 
<STRING>\\n       { *s++ = '\n'; } 
<STRING>\\t       { *s++ = '\t'; } 
<STRING>\\\"      { *s++ = '\"'; } 
<STRING>\"        { 
                    *s = 0; 
                    BEGIN(INITIAL);               
                    hashInsert(buf, LIT_STRING);      
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

#include "y.tab.c"
#include "main.c"
#include "hash.c"

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

