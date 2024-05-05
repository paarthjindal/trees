#ifndef DEQUE_H
#define DEQUE_H

typedef int ElementType;

typedef struct node* nodeptr;
typedef struct node node;

typedef struct que* queptr;
typedef struct que que;

struct que{
    nodeptr front;
    nodeptr back;
    int size;
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
int IsEmpty(queptr qu);
int Size(queptr qu);
#endif