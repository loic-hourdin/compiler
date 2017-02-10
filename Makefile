TARGET=texcc
CC=gcc
CFLAGS=-g
#DEBUG=--debug --verbose

all: ./$(TARGET)

./$(TARGET): EXPRc.c EXPR.tab.o lex.yy.o lib.o
	gcc -o $@ $^

EXPR.tab.o: EXPR.tab.c lib.h

EXPR.tab.c: EXPR.y
	bison -d $(DEBUG) $<

lex.yy.o: lex.yy.c

lex.yy.c: EXPR.lex EXPR.tab.c
	flex EXPR.lex

lib.o: CFLAGS+=-Wall -Wextra
lib.o: lib.c lib.h

clean:
	rm -f $(TARGET) *.o EXPR.tab.c EXPR.tab.h lex.yy.c *~
