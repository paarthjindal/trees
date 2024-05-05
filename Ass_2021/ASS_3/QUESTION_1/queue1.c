#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "queue1.h"
#include "tree_node1.h"
Queueptr CreateQueue(int s){
    assert(s>0);
    Queueptr qu = (Queueptr)malloc(sizeof(Queue));
    assert(qu!=NULL);
    qu->size = s;
    qu->front = 0;
    qu->rear = -1;

    qu->arr = (nodeptr*)malloc((s+1)*sizeof(nodeptr));
    assert(qu->arr!=NULL);
    qu->num_elements = 0;
    return qu;
}

void Enqueue(Queueptr q, nodeptr x)
{
    if(!IsFull(q)){
        q->rear = (q->rear+1)%(q->size);
        q->arr[q->rear] = x;
        q->num_elements+= 1;

        return ;
    }
}

void Dequeue(Queueptr q){
    if(!IsEmpty(q)){
        nodeptr x;
        x = q->arr[q->front];
        q->front = (q->front+1)%(q->size);
        q->num_elements -=1;
    }
}

int IsEmpty(Queueptr q){
    return (q->rear==-1);//returns 1 if empty.
}

int IsFull(Queueptr q){
    return (q->num_elements == q->size); 
}
void clearQueue(Queueptr q){
    q->front = 0;
    q->rear  =-1;
    q->num_elements = 0;
}

void DeleteQueue(Queueptr q){
    free(q->arr);
    free(q);
    return ;
}

void printQueue(Queueptr Q){
    if(Q->rear > Q->front){
        for(int i=Q->front; i<=Q->rear; i++ ){
            printf("%d ", (Q->arr[i]->element));
        }
    }
    else{
        for(int i=Q->front; i<=Q->size-1; i++){
            printf("%d ", Q->arr[i]->element);
        }
        for(int i=0;i<=Q->rear ; i++){
            printf("%d ",(Q->arr[i]->element) );
        }
    }
}
nodeptr Top(Queueptr q){
    return q->arr[q->front];
}