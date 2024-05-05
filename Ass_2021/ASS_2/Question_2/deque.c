#include "deque.h"
#include<stdio.h>
#include<stdlib.h>

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
        printf("%d ", temp->ele);
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

int IsEmpty(queptr qu){ //return 1 if empty.
    if(qu->size == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int Size(queptr qu){
    return qu->size;
}