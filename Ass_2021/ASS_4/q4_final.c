#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef long long int ll;
typedef ll Element;
typedef struct Heap*  Heap; 
struct Heap{
    ll iSize;//current size
    ll iCapacity;//total capacity
    Element* array; 
};

Heap init(ll size);
void insert_min_heap(Heap h, ll ele);
void PrintArray(Heap h);
ll delete_min_heap(Heap h);
Heap create_min_heap(ll *arr, ll size);
void min_heapify(Heap h, ll idx);

Heap init(ll size){
    Heap h = (Heap)malloc(sizeof(struct Heap));
    assert(h!=NULL);
    h->iCapacity = size;
    h->iSize = 0;

    h->array = (Element*)malloc(sizeof(Element)*(size+1));
    h->array[0] = -10000000;
    return h;
}

ll isFull(Heap h){
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
    ll curr_idx = h->iSize;
    h->array[curr_idx] = ele;

    while( h->array[curr_idx/2] > h->array[curr_idx]){
        Element temp = h->array[curr_idx];
        h->array[curr_idx] = h->array[curr_idx/2];
        h->array[curr_idx/2] = temp;
        curr_idx = curr_idx/2;
    }
}

void PrintArray(Heap h){
    for(ll i=1;i<=h->iSize ; i++){
        printf("%lld ", h->array[i]);
    }
    printf("\n");
}

ll delete_min_heap(Heap h){
    ll temp = h->array[1];
    h->array[1] = h->array[h->iSize];
    h->iSize-=1;

    ll curr_idx = 1;
    min_heapify(h,curr_idx);
     
    return temp;
   
}

void min_heapify(Heap H, ll idx){
    
    ll left = 2*idx;
    ll right = 2*idx+1;
    //printf("%lld\n", idx );
    if(right<=H->iSize){
        if(H->array[left] < H->array[right] && H->array[left] < H->array[idx]){
            ll temp = H->array[left];
            H->array[left] = H->array[idx];
            H->array[idx]=temp;
            idx = 2*idx;
        }
        else if(H->array[left] >= H->array[right] && H->array[right] < H->array[idx])
        {
            ll temp = H->array[right];
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
            ll temp = H->array[left];
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


Heap create_min_heap(ll *arr, ll size){
    Heap h = init(size);
    for(ll i=0;i<size; i++){
        h->array[i+1] = arr[i];
        h->iSize+=1;
    }
    //leaf nodes from n/2+1 to n

    for(ll i=size/2; i>=1; i--){
        min_heapify(h , i);
        //PrintArray(h);
    }
    return h;
}


int cmpfunc(const void* a , const void*b){
    return (*(ll*)a - *(ll*)b);
}

void helper(Heap h, ll cost){
    //PrintArray(h);
    if(h->iSize == 2){
        ll ans = h->array[1]+h->array[2];
        printf("%lld\n", cost+ans);
        return ;
    }

    ll a = delete_min_heap(h);
    ll b = delete_min_heap(h);
    
    insert_min_heap(h , a+b);
    cost+=(a+b);
    helper(h , cost);
}

int main(){
    ll l,d;
    scanf("%lld %lld ", &l, &d);

    ll arr[d];
    for(ll i=0;i<d; i++){
        scanf("%lld", &arr[i]);
    }
    qsort(arr , d , sizeof(ll) , cmpfunc);
    Heap h = init(d);
    for(int i=1; i<=d ; i++){
        
        h->array[i] = arr[i-1];
        //printf("%lld ", h->array[i]);
    }
    h->iSize = d;
    ll cost = 0;
    //PrintArray(h);
    helper(h, cost);

}

