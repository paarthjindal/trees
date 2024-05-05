#ifndef QUEUE_H
#define QUEUE_H
#include "tree.h"
typedef struct Queue Queue;
typedef struct Queue* Queueptr; 

struct Queue{
    int size;
    int front,rear;
    nodeptr* arr;
    int num_elements;
};

Queueptr CreateQueue(int s);
void Enqueue(Queueptr q , nodeptr x);
void Dequeue(Queueptr q);
nodeptr Top(Queueptr q);
int IsEmpty(Queueptr q);
int IsFull(Queueptr q);

void printQueue(Queueptr Q);
void clearQueue(Queueptr Q);
void deleteQueue(Queueptr Q);
void printQueue(Queueptr Q);
#endif