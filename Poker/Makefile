CC=c++
CFLAGS= -Wall -std=c++11
LDFLAGS = -lm

all: Poker

Poker: Poker.o Player.o Cards.o Board.o main.o
	${CC} Poker.o PlayerHuman.o Cards.o Board.o main.o ${LDFAGS} -o Poker	
main.o : main.cpp
	${CC} ${CFLAGS} -c main.cpp

Poker.o : Poker.cpp Poker.h
	${CC} ${CFLAGS} -c Poker.cpp

Player.o : PlayerHuman.cpp PlayerHuman.h Player.h
	${CC} ${CFLAGS} -c PlayerHuman.cpp

Cards.o : Cards.cpp Cards.h
	${CC} ${CFLAGS} -c Cards.cpp

Board.o : Board.cpp Board.h
	${CC} ${CFLAGS} -c Board.cpp
