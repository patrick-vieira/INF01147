int main(int argc, char** argv) {
  
  // se existe um arquivo lê ele
  // se não lê do console;
  if (argc > 1) { 
    yyin = fopen(argv[1], "r");
  }

  hashInit();

  int token = yylex();

  while(running) {
    switch(token){
      case KW_CHAR:             printf("KW_CHAR '%d'\n", token);            break;      
      case KW_INT:              printf("KW_INT '%d'\n", token);             break; 
      case KW_FLOAT:            printf("KW_FLOAT '%d'\n", token);           break;   

      case KW_IF:               printf("KW_IF '%d'\n", token);              break; 
      case KW_THEN:             printf("KW_THEN '%d'\n", token);            break;   
      case KW_ELSE:             printf("KW_ELSE '%d'\n", token);            break; 
      case KW_WHILE:            printf("KW_WHILE '%d'\n", token);           break; 
      case KW_GOTO:             printf("KW_GOTO '%d'\n", token);            break;
      case KW_READ:             printf("KW_READ '%d'\n", token);            break;
      case KW_PRINT:            printf("KW_PRINT '%d'\n", token);           break; 
      case KW_RETURN:           printf("KW_RETURN '%d'\n", token);          break;  

      case OPERATOR_LE:         printf("OPERATOR_LE '%d'\n", token);        break;
      case OPERATOR_GE:         printf("OPERATOR_GE '%d'\n", token);        break;
      case OPERATOR_EQ:         printf("OPERATOR_EQ '%d'\n", token);        break; 
      case OPERATOR_DIF:        printf("OPERATOR_DIF '%d'\n", token);       break;  

      case TK_IDENTIFIER:       printf("TK_IDENTIFIER '%d'\n", token);      break;  

      case LIT_INTEGER:         printf("LIT_INTEGER '%d'\n", token);        break;  
      case LIT_CHAR:            printf("LIT_CHAR '%d'\n", token);           break;  
      case LIT_STRING:          printf("LIT_STRING '%d'\n", token);         break;  

      case TOKEN_ERROR:         printf("TOKEN_ERROR '%d'\n", token);        break;  
      default:                  printf("token '%d'\n", token);              break; 

    }
    token = yylex();  
  }
  printf("\n ---------- \n Numero de linhas = [%d] \n ---------- \n", getLineNumber());    
  hashPrint();
}