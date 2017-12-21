CC = g++
OBJS = DLTest.o DLList.o Node.o
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

DLTest: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o DLTest

DLList.h: Node.h

DLTest.o: DLTest.cpp DLList.h
	$(CC) $(CFLAGS) DLTest.cpp 

DLList.o: DLList.cpp DLList.h
	$(CC) $(CFLAGS) DLList.cpp

Node.o: Node.cpp Node.h
	$(CC) $(CFLAGS) Node.cpp 

clean:
	\rm *.o DLTest

tar:
	tar cfv DLList.tar DLList.cpp DLList.h DLTest.cpp Node.cpp Node.h makefile README.txt
