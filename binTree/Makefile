CC=g++
CLFAGS=-Wall -std=c++11
LDFLAGS=-lm

all: binTree

binTree: binTree.o
	${CC} binTree.o ${LDFLAGS} -o binTree

binTree.o:
	${CC} -c ${CFLAGS} binTree.cpp

