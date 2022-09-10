#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stddef.h>

#define INITIAL_SIZE 5

typedef struct myStack
{
    int* numbers;
    int capacity;
    int maxSize;
}stack;

stack* myStack = NULL;

stack* create();
void push(int val);
int pop();
void resize(int newSize);
void print();
void freeMem();

int main(int argc , char** argv)
{
    myStack=create();

    push(1);
    push(2);
    push(4);

    print();
    freeMem();
    return 0;
}

stack* create()
{
    myStack = malloc(sizeof(stack*));
    assert(myStack != NULL);

    myStack->numbers = malloc(INITIAL_SIZE*sizeof(int));
    assert(myStack->numbers != NULL);

    myStack->capacity = 0;
    myStack->maxSize = INITIAL_SIZE;
}

void push(int val)
{
    if(myStack->capacity == myStack->maxSize)
    {
        resize((myStack->maxSize)*2);
    }
    myStack->numbers[myStack->capacity]=val;
    myStack->capacity++;
}

void resize(int newSize)
{
    int * temp = malloc(sizeof(int)*newSize);

    for(ptrdiff_t i=0;i<myStack->maxSize;i++){
        temp[i] = myStack->numbers[i];
    }
    free(myStack->numbers);

    myStack->numbers=temp;
    myStack->maxSize = newSize;
}

int pop()
{
    if(myStack->capacity == 0)
    {
        fprintf(stderr,"Stack is empty!");
        return 1;
    }
    myStack->capacity--;

    if (myStack->capacity == myStack->maxSize / 4)
    {
        resize(myStack->maxSize / 2);
    }

    return myStack->numbers[myStack->capacity+1];
}

void print()
{
    for(int i=(myStack->capacity)-1;i>=0;i--)
    {
        printf("%d ",myStack->numbers[i]);
    }
    printf("\n");
}

void freeMem()
{
    free(myStack->numbers);
    free(myStack);
}