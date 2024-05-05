#ifndef _HEAP_H_
#define _HEAP_H_
typedef struct Heap
{
    long int* arr;
    int count;
    long int t_exp;
} Heap;
Heap* create_heap(int n);
void heapify(Heap* h);
void insert(Heap* h,long int val);
long int extractMin(Heap* h);
void swap(long int* a,long int* b);
int maxKnobs(long int* a,int n);
#endif