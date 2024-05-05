#ifndef __HEAP_H
#define __HEAP_H
typedef struct Heap
{
    int* arr;
    int count;
} Heap;
Heap* create_heap(int n);
void heapify(Heap* h);
void insert(Heap* h,int val);
int extractMin(Heap* h);
void swap(int* a,int* b);
void print_smallest_derangement(Heap* h,int* a);
#endif