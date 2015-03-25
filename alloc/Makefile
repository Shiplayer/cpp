CC=gcc
CLFAGS=-Wall -std=c99

all: clean alloc

alloc: alloc.o
	${CC} alloc.o -o alloc

alloc.o:
	${CC} -c ${CLFAGS} alloc.c -o alloc.o

clean:
	rm -rf alloc.o alloc

