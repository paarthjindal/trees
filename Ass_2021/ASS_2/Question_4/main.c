#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int ElementType ;

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

    for(int i=s->top ; i>=0 ; i--){
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main(){

    
    int n,m;
    scanf("%d %d", &n, &m);

    int arr[n][m];
    
    int max_arr[n];
    for(int i=n-1; i>=0 ; i--){
        char str[m+1];
    
        scanf("%s" ,str);
        for(int j=0;j<m; j++){
            if(str[j] == '*'){
                arr[i][j] = 0;
            }
            else{
                arr[i][j] = 1;
            }
        }
    }

    //printf("jkbvf\n");
    // for(int i=0;i<n; i++)
    // {
    //     for(int j=0;j<m; j++){
    //         printf("%d", arr[i][j]);
    //     }
    //     printf("\n");
    // }
    
    int height[m];
    for(int i=0;i<m;i++){
        height[i]=0;
    }

    for(int t=n-1 ; t>=0; t--){ 
//for loop begins ....
    
    for(int i=0;i<m;i++){
        if( arr[t][i] == 0){
            height[i] = 0;
        }
        else{
            height[i]+=1;
        }
    }

    // for(int i=0;i<m; i++){
    //     printf("%d ", height[i]);
    // }

    stackptr st = Intial_Stack(m);
    int left_boundary[m];

    for(int i=0;i<m; i++){
        
        if(IsEmpty(st) == 1){
            left_boundary[i] = 0;
            push(st,i);
        }
        else{
            while(IsEmpty(st) == 0 && height[i] <= height[Top(st)] ){
                pop(st);
            }
            if(IsEmpty(st) == 1){
                left_boundary[i] = 0;
                push(st,i);
                continue;
            }
            left_boundary[i] = Top(st)+1;
            push(st,i);
        }
    }
    // printf("\n");
    // for(int i=0;i<m;i++){
    //     printf("%d ", left_boundary[i] );
    // }

    int right_boundary[m];
    clearStack(st);
    for(int i=m-1;i>=0; i--){
        
        if(IsEmpty(st) == 1){
            right_boundary[i] = m-1;
            push(st,i);
        }
        else{
            while(IsEmpty(st) == 0 && height[i] <= height[Top(st)] ){
                pop(st);
            }
            if(IsEmpty(st) == 1){
                right_boundary[i] = m-1;
                push(st,i);
                continue;
            }
            right_boundary[i] = Top(st)-1;
            push(st,i);
        }
    }
    // printf("\n");
    // for(int i=0;i<m;i++){
    //     printf("%d ", right_boundary[i] );
    // }

    int maxx_area = 0;
    for(int i=0;i<m; i++){
        int width=(right_boundary[i] - left_boundary[i]+1)*height[i];
        if(width > maxx_area){
            maxx_area = width;
        }
    }
    //printf("\n%d\n" , maxx_area);
    max_arr[t] = maxx_area;
    clearStack(st);
    }

    int maxx = -1;
    for(int i=0;i<n; i++){
        if(max_arr[i] > maxx){
            maxx = max_arr[i];
        }
    }
    printf("%d", maxx);
}