#include<stdio.h>
#include<stdlib.h>

typedef long long int ElementType;

typedef struct node* nodeptr;
typedef struct node node;

typedef struct que* queptr;
typedef struct que que;

struct que{
    nodeptr front;
    nodeptr back;
    long long int size;
};

struct node{
    nodeptr right;
    nodeptr left;
    ElementType ele;
};

queptr create_queue();
void push_front(queptr qu , ElementType x);
void print_deque(queptr qu);
void push_back(queptr qu , ElementType x);
ElementType pop_front(queptr qu);
ElementType pop_back(queptr qu);
ElementType Front(queptr qu);
ElementType Back(queptr qu);
long long int IsEmpty(queptr qu);
long long int Size(queptr qu);



queptr create_queue(){
    queptr qu = (queptr)malloc(sizeof(que));
    qu->back = NULL;
    qu->front = NULL;
    qu->size= 0;
    return qu;
}

void push_front(queptr qu , ElementType x){

    nodeptr temp = qu->front;
    nodeptr new_node =(nodeptr)malloc(sizeof(node));
    new_node->ele = x;
    new_node->right = temp;
    new_node->left = NULL;

    if(qu->size == 0){
        qu->front = new_node;
        qu->back = new_node;
        qu->size+=1;
        return ;
    }
    
    qu->front = new_node;
    temp->left = new_node;
    qu->size +=1;
}

void push_back(queptr qu , ElementType x){

    nodeptr temp = qu->back;
    nodeptr new_node =(nodeptr)malloc(sizeof(node));
    new_node->ele = x;
    new_node->right = NULL;
    new_node->left = temp;

    if(qu->size == 0){
        qu->front = new_node;
        qu->back = new_node;
        qu->size+=1;
        return ;
    }
    qu->back = new_node;
    temp->right = qu->back;
    qu->size+=1;
}

ElementType pop_front(queptr qu){

    if(qu->size == 1){
        ElementType x = qu->front->ele;
        free(qu->front);
        qu->front = qu->back= NULL;
        qu->size-=1;
        return x;
    }
    nodeptr delete_node = qu->front;
    qu->front = delete_node->right;
    delete_node->right->left = NULL;
    ElementType x = delete_node->ele;
    free(delete_node);
    qu->size-=1;
    return x;
}

ElementType pop_back(queptr qu){
    if(qu->size == 1){
        ElementType x = qu->front->ele;
        free(qu->front);
        qu->front = qu->back= NULL;
        qu->size-=1;
        return x;
    }
    nodeptr delete_node = qu->back;
    qu->back = delete_node->left;
    delete_node->left->right = NULL;
    ElementType x = delete_node->ele;

    free(delete_node);
    qu->size-=1;
    return x;
}

void print_deque(queptr qu){
    nodeptr temp = qu->front;

    while(temp!=NULL){
        printf("%lld ", temp->ele);
        temp = temp->right;
    }
    printf("\n");
}

ElementType Front(queptr qu){
    return qu->front->ele;
}
ElementType Back(queptr qu){
    return qu->back->ele;
}

long long int IsEmpty(queptr qu){ //return 1 if empty.
    if(qu->size == 0){
        return 1;
    }
    else{
        return 0;
    }
}

long long int Size(queptr qu){
    return qu->size;
}


long long int main(){
    long long int n,m;
    scanf("%lld %lld", &n , &m);

    ElementType arr[n];

    for(long long int i=0;i<n;i++){
        scanf("%lld", &arr[i]);
    }

    queptr dq = create_queue();

    push_front(dq , 0);

    for(long long int i=1;i<m; i++){
        if(arr[i] > arr[Back(dq)]){
            push_back(dq , i);
        }
        else{
            while( IsEmpty(dq) == 0 && arr[i] < arr[Back(dq)] ){
                pop_back(dq);
            }
            push_back(dq , i);
        }
    }

    printf("%lld " , arr[Front(dq)]);

    for(long long int i=1; i<=n-m ; i++){
        //prlong long int_deque(dq);
        if( Front(dq) < i){
            pop_front(dq);
        }
        if(IsEmpty(dq)==1 || arr[i+m-1] > arr[Back(dq)]){
            push_back(dq , i+m-1);
        }
        else{
            while( IsEmpty(dq) == 0 && arr[i+m-1] < arr[Back(dq)]){
                //prlong long intf("%lld->pop ", Back(dq));
                pop_back(dq);
            }
            push_back(dq , i+m-1);
        }
        printf("%lld " , arr[Front(dq)]);
    }
}