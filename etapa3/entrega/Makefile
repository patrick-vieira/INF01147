#
# UFRGS - Compiladores B - Marcelo Johann - 2021/2 - Etapa 3
#


etapa3: main.o lex.yy.o y.tab.o hash.o ast.o
	gcc main.o lex.yy.o y.tab.o hash.o ast.o -o etapa3

main.o: main.c
	gcc -c main.c

ast.o: ast.c y.tab.o
	gcc -c ast.c
	
hash.o: hash.c
	gcc -c hash.c

y.tab.o: y.tab.c
	gcc -c y.tab.c

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

y.tab.c: parser.y
	yacc -d parser.y

lex.yy.c: scanner.l y.tab.c ast.c
	lex scanner.l


clean:
	rm lex.yy.c y.tab.c y.tab.h *.o etapa3
