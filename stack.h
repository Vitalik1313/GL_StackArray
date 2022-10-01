#ifndef SOME_HEADER_H_
#define SOME_HEADER_H_

#define INITIAL_SIZE 5

typedef struct myStack
{
    int* numbers;
    int capacity;
    int maxSize;
}stack;

extern stack* myStack;

stack* create(stack* myStack);
void push(int val,stack* myStack);
int pop(stack* myStack);
void resize(int newSize,stack* myStack);
void print(stack* myStack);
void freeMem(stack* myStack);

#endif
