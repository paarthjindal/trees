#include"heaps.h"
#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a, const void*b){
    return (*(int*)a - *(int*)b);
}

void helper(Heap h, int cost){
    //PrintArray(h);
    if(h->iSize == 2){
        int ans = h->array[1]+h->array[2];
        printf("%d\n", cost+ans);
        return ;
    }

    int a = delete_min_heap(h);
    int b = delete_min_heap(h);
    
    insert_min_heap(h , a+b);
    cost+=(a+b);
    helper(h , cost);
}

int main(){
    int l,d;
    scanf("%d %d ", &l, &d);

    int arr[d];
    for(int i=0;i<d; i++){
        scanf("%d", &arr[i]);
    }
    //qsort(arr , d , sizeof(int) , cmp);
    Heap h = create_min_heap(arr, d);
    int cost = 0;
    //PrintArray(h);
    helper(h, cost);
    
}