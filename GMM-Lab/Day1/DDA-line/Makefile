CC=g++
LDFLAGS=-lglut -lGLU -lGL

all: main

main: main.o
	${CC} main.o -o main ${LDFLAGS}

main.o: main.cpp
	${CC} -c main.cpp -o main.o

clean:
	rm main.o main
