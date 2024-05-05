#include<stdio.h>
#include<stdlib.h>
//#include<algorithm>
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

stackptr intial_Stack(long long int s){

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



long long int gcd(long long int n1, long long int n2) {
    if (n2 != 0)
        return gcd(n2, n1 % n2);
    else
        return n1;
}

long long int LCM(long long int n1, long long int n2){
    
    long long int lcm;
    lcm = (n1 * n2) / gcd(n1,n2);
    return lcm;
}

void helper(stackptr st ,long long int n, long long int* arr){
    push(st , arr[0]);

    for(long long int i=1; i<n; i++){
        long long int temp = arr[i];

        while(IsEmpty(st)==0 && gcd(Top(st) , temp)>1 ){
            temp = LCM(temp , Top(st));
            pop(st);
        }

        push(st , temp);
    }
}

long long int get_size(stack st){
    long long int count = 0;

    while(IsEmpty(&st) != 1){
        pop(&st);
        count+=1;
    }
    return count;
}
int main(){
    long long int n;
    scanf("%lld", &n);
    long long int arr[n];
    for(long long int i=0;i<n;i++){
        scanf("%lld", &arr[i]);
    }

    stackptr st = intial_Stack(n);
    
    helper(st,n,arr);
    //printStack(st);
    
    long long int arr2[n];

    long long int count= 0;
    //get_size(st);
    while(IsEmpty(st)==0){
        arr2[count] = Top(st);
        pop(st);
        count+=1;
    }
    //printf("%lld\n" , count);
    helper(st , count , arr2);
    printf("%lld\n" , get_size(*st));
    printStack(st);
    
}