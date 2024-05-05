#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef long long int ElementType ;

typedef struct stack* stackptr;
typedef struct stack stack;

struct stack{
    long long int size;
    ElementType* arr;
    long long int top;
};

stackptr Intial_Stack(long long int s);
long long int IsEmpty(stackptr s);
long long int IsFull(stackptr s);
void push(stackptr s , ElementType x);
void pop(stackptr s);
ElementType Top(stackptr s);
void clearStack(stackptr s);
void DeleteStack(stackptr s);
void printStack(stackptr s);

stackptr Intial_Stack(long long int s){

    stackptr ptr_stack = (stackptr)malloc(sizeof(stack));
    assert(ptr_stack!=NULL);
    ptr_stack->arr = (ElementType*)malloc(s*sizeof(ElementType));
    assert(ptr_stack->arr!=NULL);

    ptr_stack->size = s;
    ptr_stack->top = -1;
    return ptr_stack;
}

long long int IsEmpty(stackptr s){
    if(s->top == -1){
        return 1;   //empty
    }
    else{
        return 0;
    }
}

long long int IsFull(stackptr s){
    if(s->top >= s->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(stackptr s , ElementType x){
    long long int b = IsFull(s);

    if(b==0){
        s->top+=1;
        s->arr[s->top] = x;
    }
}

void pop(stackptr s){
    long long int b = IsEmpty(s);

    if(b==0){
        s->top-=1;
    }
}

ElementType Top(stackptr s){
    long long int b = IsEmpty(s);

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
    long long int t = s->top;

    for(long long int i=s->top ; i>=0 ; i--){
        printf("%lld ", s->arr[i]);
    }
    printf("\n");
}

long long int main(){
    long long int n;
    scanf("%lld", &n);

    long long int arr[n];
    long long int arr1[n];
    for(long long int i=0; i<n; i++){
        scanf("%lld", &arr[i]);
        arr1[n-i-1]=arr[i];
    }

    long long int ans=0;
    stackptr st = Intial_Stack(n);

    for(long long int i=0;i<n; i++){
        if(IsEmpty(st)==1){
            push(st , i);
        }
        else{
            while(IsEmpty(st) == 0 && arr[i] > arr[Top(st)] ){
                ans+= (i-Top(st)+ 1);
                pop(st);
            }
            push(st , i);
        }
    }
    //prlong long long long intf("%lld", ans);
    clearStack(st);

    for(long long int i=0;i<n; i++){
        if(IsEmpty(st)==1){
            push(st , i);
        }
        else{
            while(IsEmpty(st) == 0 && arr1[i] > arr1[Top(st)] ){
                ans+= (i-Top(st)+ 1);
                pop(st);
            }
            push(st , i);
        }
    }
    
    printf("%lld", ans);
}