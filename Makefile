CC=gcc
CFLAGS=-I.

stack: MyStack.o stack.o
	$(CC) MyStack.o stack.o -o stack

MyStack.o: MyStack.c
	$(CC) -c MyStack.c

stack.o: stack.c
	$(CC) -c stack.c

clean:
	rm *.o