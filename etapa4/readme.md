Para executar via VSCode.

Adicionar as seguintes tasks no arquivo tasks.json

```
    {
        "type": "shell",
        "label": "lex",
        "command": "/usr/bin/lex",
        "args": ["./scanner.l"]
    },
    {
        "label": "build",
        "dependsOn": [
            "lex", 
            "C/C++: gcc build active file"
        ]
    }

```

To execute open the file lex


O Arquivo de Tokens da etapa1, passa a ser usado nas definições do arquivo usado pelo yacc, a numeração é feita de forma automatica.

yacc parser.y -d

-d gera o arquivo .h contendo as definições dos tokens

para rodar no terminal 

 ``make clean && make && echo && ./etapa2 input.txt``




verificar conflitos;
yacc -v parser.y

 etapa 4.

 definições 


 duvidas:
era para dar erro?

int fn-b() {}
int fn() {  
  a = a + fn-b; 
}