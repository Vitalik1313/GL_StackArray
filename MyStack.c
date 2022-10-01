#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stddef.h>
#include"stack.h"

stack* myStack = NULL;

int main(int argc , char** argv)
{
    myStack=create(myStack);

    push(1,myStack);
    push(2,myStack);
    push(4,myStack);
    push(4,myStack);
    push(4,myStack);
    push(4,myStack);

    print(myStack);
    freeMem(myStack);
    return 0;
}
