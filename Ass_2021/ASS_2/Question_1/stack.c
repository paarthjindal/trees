#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"stack.h"

stackptr Intial_Stack(int s){

    stackptr ptr_stack = (stackptr)malloc(sizeof(stack));
    assert(ptr_stack!=NULL);
    ptr_stack->arr = (ElementType*)malloc(s*sizeof(ElementType));
    assert(ptr_stack->arr!=NULL);

    ptr_stack->size = s;
    ptr_stack->top = -1;
    return ptr_stack;
}

int IsEmpty(stackptr s){
    if(s->top == -1){
        return 1;   //empty
    }
    else{
        return 0;
    }
}

int IsFull(stackptr s){
    if(s->top >= s->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(stackptr s , ElementType x){
    int b = IsFull(s);

    if(b==0){
        s->top+=1;
        s->arr[s->top] = x;
    }
}

void pop(stackptr s){
    int b = IsEmpty(s);

    if(b==0){
        s->top-=1;
    }
}

ElementType Top(stackptr s){
    int b = IsEmpty(s);

    if(b==0){
        return s->arr[s->top];
    }
}

void clearStack(stackptr s){
    s->top = -1;
}

void DeleteStack(stackptr s){
    free(s->arr);
    free(s);
}

void printStack(stackptr s){
    int t = s->top;

    for(int i=s->top ; i>=0 ; i--){
        printf("%lld ", s->arr[i]);
    }
    printf("\n");
}