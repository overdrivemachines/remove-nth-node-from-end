
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

remove-nth-node-from-end: remove-nth-node-from-end.o
	$(CC) $(CFLAGS) -o remove-nth-node-from-end remove-nth-node-from-end.o

remove-nth-node-from-end.o: remove-nth-node-from-end.cpp
	$(CC) $(CFLAGS) -c remove-nth-node-from-end.cpp

clean:
	rm -rf remove-nth-node-from-end remove-nth-node-from-end.o
