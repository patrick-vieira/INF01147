#
# UFRGS - Compiladores B - Marcelo Johann - 2021/2 - Etapa 3
#
# Makefile for single compiler call
# All source files must be included from code embedded in scanner.l
# In our case, you probably need #include "hash.c" at the beginning
# and #include "main.c" in the last part of the scanner.l
#

etapa3: yacc lex
	gcc -o etapa3 lex.yy.c
yacc:
	yacc -d parser.y	
lex: scanner.l
	lex scanner.l

yaccv:
	yacc -v parser.y

clean:
	rm lex.yy.c etapa3 y.tab.c y.tab.h
