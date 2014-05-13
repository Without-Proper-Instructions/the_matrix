CC=gcc
CFLAGS=-Wall -g

all: matrix

matrix: matrix.c
	$(CC) $(CFLAGS) matrix.c -o bash

clean:
	rm -fv bash
