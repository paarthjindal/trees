//creating min heap.

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "heaps.h"

Heap init(int size){
    Heap h = (Heap)malloc(sizeof(struct Heap));
    assert(h!=NULL);
    h->iCapacity = size;
    h->iSize = 0;

    h->array = (Element*)malloc(sizeof(Element)*(size+1));
    h->array[0] = -10000000;
    return h;
}

int isFull(Heap h){
    if(h->iCapacity == h->iSize){
        return 1;
    }
    return 0;//returns 1 if full and 0 otherwise.
}
void insert_min_heap(Heap h, Element ele){
    if(isFull(h)==1){
        printf("Heap full\n");
        return ;
    }
    h->iSize +=1;
    //now we will insert an element at poisition iSize
    int curr_idx = h->iSize;
    h->array[curr_idx] = ele;

    while( h->array[curr_idx/2] > h->array[curr_idx]){
        Element temp = h->array[curr_idx];
        h->array[curr_idx] = h->array[curr_idx/2];
        h->array[curr_idx/2] = temp;
        curr_idx = curr_idx/2;
    }
}

void PrintArray(Heap h){
    for(int i=1;i<=h->iSize ; i++){
        printf("%d ", h->array[i]);
    }
    printf("\n");
}

int delete_min_heap(Heap h){
    int temp = h->array[1];
    h->array[1] = h->array[h->iSize];
    h->iSize-=1;

    int curr_idx = 1;
    min_heapify(h,curr_idx);
     
    return temp;
   
}

void min_heapify(Heap H, int idx){
    
    int left = 2*idx;
    int right = 2*idx+1;
    //printf("%d\n", idx );
    if(right<=H->iSize){
        if(H->array[left] < H->array[right] && H->array[left] < H->array[idx]){
            int temp = H->array[left];
            H->array[left] = H->array[idx];
            H->array[idx]=temp;
            idx = 2*idx;
        }
        else if(H->array[left] >= H->array[right] && H->array[right] < H->array[idx])
        {
            int temp = H->array[right];
            H->array[right] = H->array[idx];
            H->array[idx]=temp;
            idx = 2*idx+1;
        }
        else{
            return ;
        }
    } 
    else if(left<=H->iSize){
        if(H->array[left] < H->array[idx]){
            int temp = H->array[left];
            H->array[left] = H->array[idx];
            H->array[idx]=temp;
            idx = 2*idx;
        }
        else{
            return ;
        }
    }
    else{
        return;
    }
    return min_heapify(H , idx);
}


Heap create_min_heap(int *arr, int size){
    Heap h = init(size);
    for(int i=0;i<size; i++){
        h->array[i+1] = arr[i];
        h->iSize+=1;
    }
    //leaf nodes from n/2+1 to n

    for(int i=size/2; i>=1; i--){
        min_heapify(h , i);
        //PrintArray(h);
    }
    return h;
}