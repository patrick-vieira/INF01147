#
# UFRGS - Compiladores B - Marcelo Johann - 2021/2 - Etapa 1
#
# Makefile for single compiler call
# All source files must be included from code embedded in scanner.l
# In our case, you probably need #include "hash.c" at the beginning
# and #include "main.c" in the last part of the scanner.l
#

etapa2: yacc lex
	gcc -o etapa2 lex.yy.c
yacc:
	yacc -d parser.y	
lex: scanner.l
	lex scanner.l

clean:
	rm lex.yy.c etapa2 y.tab.c y.tab.h
