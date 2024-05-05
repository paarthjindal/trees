#ifndef STACK_H
#define STACK_H

typedef long long int ElementType ;

typedef struct stack* stackptr;
typedef struct stack stack;

struct stack{
    int size;
    ElementType* arr;
    int top;
};

stackptr Intial_Stack(int s);
int IsEmpty(stackptr s);
int IsFull(stackptr s);
void push(stackptr s , ElementType x);
void pop(stackptr s);
ElementType Top(stackptr s);
void clearStack(stackptr s);
void DeleteStack(stackptr s);
void printStack(stackptr s);

#endif  