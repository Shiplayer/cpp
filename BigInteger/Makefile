CC=c++
CFLAGS= -Wall -std=c++11
LDFLAGS = -lm

all: BigInteger

BigInteger: BigInteger.o main.o
	${CC} BigInteger.o main.o ${LDFAGS} -o BigInteger
	
main.o : main.cpp
	${CC} ${CFLAGS} -c main.cpp

BigInteger.o : BigInteger.cpp BigInteger.h
	${CC} ${CFLAGS} -c BigInteger.cpp
