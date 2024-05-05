#ifndef heap_h
#define heap_h

typedef int Element;
typedef struct Heap*  Heap; 
struct Heap{
    int iSize;//current size
    int iCapacity;//total capacity
    Element* array; 
};

Heap init(int size);
void insert_min_heap(Heap h, int ele);
void PrintArray(Heap h);
int delete_min_heap(Heap h);
Heap create_min_heap(int *arr, int size);
void min_heapify(Heap h, int idx);
#endif

