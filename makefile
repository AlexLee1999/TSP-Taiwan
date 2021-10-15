
CC = g++
CFLAGS = -c

OPTFLAGS = -O3 -std=c++11 -Wall

BIN = Tsp

${BIN}		: main.o graph.o node.o 
			$(CC) $(OPTFLAGS) -o ${BIN} main.o graph.o node.o

main.o 	   	: src/main.cpp
			$(CC) $(OPTFLAGS) $(CFLAGS) src/main.cpp

graph.o	    : src/graph.cpp src/graph.h
			$(CC) $(OPTFLAGS) $(CFLAGS) src/graph.cpp

node.o	    : src/node.cpp src/node.h
			$(CC) $(OPTFLAGS) $(CFLAGS) src/node.cpp

clean:
			rm -rf *.o  ${BIN}

