#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stddef.h>
#include"stack.h"

stack* create(stack* myStack)
{
    myStack = malloc(sizeof(stack*));
    assert(myStack != NULL);

    myStack->numbers = malloc(INITIAL_SIZE*sizeof(int));
    assert(myStack->numbers != NULL);

    myStack->capacity = 0;
    myStack->maxSize = INITIAL_SIZE;
}

void push(int val,stack* myStack)
{
    if(myStack->capacity == myStack->maxSize)
    {
        resize((myStack->maxSize)*2,myStack);
    }
    myStack->numbers[myStack->capacity]=val;
    myStack->capacity++;
}

void resize(int newSize,stack* myStack)
{
    int * temp = malloc(sizeof(int)*newSize);

    for(ptrdiff_t i=0;i<myStack->maxSize;i++){
        temp[i] = myStack->numbers[i];
    }
    free(myStack->numbers);

    myStack->numbers=temp;
    myStack->maxSize = newSize;
}

int pop(stack* myStack)
{
    if(myStack->capacity == 0)
    {
        fprintf(stderr,"Stack is empty!");
        return 1;
    }
    myStack->capacity--;

    if (myStack->capacity == myStack->maxSize / 4)
    {
        resize(myStack->maxSize / 2,myStack);
    }

    return myStack->numbers[myStack->capacity+1];
}

void print(stack* myStack)
{
    for(int i=(myStack->capacity)-1;i>=0;i--)
    {
        printf("%d ",myStack->numbers[i]);
    }
    printf("\n");
}

void freeMem(stack* myStack)
{
    free(myStack->numbers);
    free(myStack);
}