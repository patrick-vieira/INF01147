To run

```
make clean && make && echo && ./etapa4 input.txt output.txt
```

To debug with GDB server

```
make clean && make && gdbserver localhost:1234 ./etapa4 input-1.txt output.txt
```



To execute open the file lex


O Arquivo de Tokens da etapa1, passa a ser usado nas definições do arquivo usado pelo yacc, a numeração é feita de forma automatica.

yacc parser.y -d

-d gera o arquivo .h contendo as definições dos tokens





verificar conflitos;
yacc -v parser.y
