#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef long long int ll;
/*
typedef ll Element;
typedef struct Heap*  Heap; 
struct Heap{
    ll iSize;//current size
    ll iCapacity;//total capacity
    Element* array; 
};

Heap init(ll size);
void insert_max_heap(Heap h, ll ele);
void PrintArray(Heap h);
ll delete_max_heap(Heap h);
Heap create_max_heap(ll *arr, ll size);
void max_heapify(Heap h, ll idx);

Heap init(ll size){
    Heap h = (Heap)malloc(sizeof(struct Heap));
    assert(h!=NULL);
    h->iCapacity = size;
    h->iSize = 0;

    h->array = (Element*)malloc(sizeof(Element)*(size+1));
    h->array[0] = 1000000009;
    return h;
}

ll isFull(Heap h){
    if(h->iCapacity == h->iSize){
        return 1;
    }
    return 0;//returns 1 if full and 0 otherwise.
}
void insert_max_heap(Heap h, Element ele){
    if(isFull(h)==1){
        printf("Heap full\n");
        return ;
    }
    h->iSize +=1;
    //now we will insert an element at poisition iSize
    ll curr_idx = h->iSize;
    h->array[curr_idx] = ele;

    while( h->array[curr_idx/2] < h->array[curr_idx]){
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

ll delete_max_heap(Heap h){
    ll temp = h->array[1];
    h->array[1] = h->array[h->iSize];
    h->iSize-=1;

    ll curr_idx = 1;
    max_heapify(h,curr_idx);
     
    return temp;
   
}

void max_heapify(Heap H, ll idx){
    
    ll left = 2*idx;
    ll right = 2*idx+1;
    //printf("%lld\n", idx );
    if(right<=H->iSize){
        if(H->array[left] > H->array[right] && H->array[left] > H->array[idx]){
            ll temp = H->array[left];
            H->array[left] = H->array[idx];
            H->array[idx]=temp;
            idx = 2*idx;
        }
        else if(H->array[left] <= H->array[right] && H->array[right] > H->array[idx])
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
        if(H->array[left] > H->array[idx]){
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
    return max_heapify(H , idx);
}


Heap create_max_heap(ll *arr, ll size){
    Heap h = init(size);
    for(ll i=0;i<size; i++){
        h->array[i+1] = arr[i];
        h->iSize+=1;
    }
    //leaf nodes from n/2+1 to n

    for(ll i=size/2; i>=1; i--){
        max_heapify(h , i);
        //PrintArray(h);
    }
    return h;
}
*/
ll sum_final = 0;

void find_max_sum(ll* arr, ll k, ll n, ll idx){
    //max_len of sub array = n-(k-1)
    
    if(k<=0){
        return ;
    }
    if(k==1){
        //printf("k==1->n=%lld\n" , n);
        ll sum = 0;
        for(ll i=0 ; i<n; i++){
            sum+=arr[i+idx];
        }
        sum_final += sum;
        return ;
    }
    ll max_sum = arr[idx];
    ll j = idx; //j is the last idx, till where we get the max_sum.
    ll temp = j;
    ll sum = arr[idx];
    
    for(int i=1;i<n-(k-1) ; i++){//iterate n-(k-1)-1 times , i.e max_len of sub array -1 times.
        sum+=arr[i+idx];
        if(max_sum < sum){
            max_sum = sum;
            j = i;
        }
    }
    
    sum_final += k*max_sum;
    //printf("%lld->%lld j=%lld sum_yet = %lld\n ", k , max_sum, j, sum_final);
    idx = j+1;

    find_max_sum(arr, k-1 , n-(idx-temp), idx);
}

int main(){
    ll n,k;
    scanf("%lld  %lld", &n, &k);

    ll arr[n];

    for(ll i=0;i<n; i++){
        scanf("%lld", &arr[n-i-1]);
    }

    //my multiplication startts from k.
    ll idx = 0;
    find_max_sum(arr , k, n , idx);
    printf("%lld\n", sum_final);
}