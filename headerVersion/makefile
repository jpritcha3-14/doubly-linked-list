CC = g++
OBJS = DLtest.o DLList.o Node.o
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
BUILD = ../build

DLtest: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o DLtest

DLList.h: Node.h

DLLtest.o: DLLtest.cpp DLList.h
	$(CC) $(CFLAGS) DLtest.cpp 

DLList.o: DLList.cpp DLList.h
	$(CC) $(CFLAGS) DLList.cpp

Node.o: Node.cpp Node.h
	$(CC) $(CFLAGS) Node.cpp 

clean:
	\rm *.o DLtest

