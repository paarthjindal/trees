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

int cmpfunc (const void * a, const void * b)
{
    if( *(long long int*)a - *(long long int*)b < 0 )
        return -1;
    if( *(long long int*)a - *(long long int*)b > 0 )
        return 1;
    return 0;
}


void helper(int idx , int k , ll mat[][k]){
    if(idx == k){
        for(int i=0;i<k; i++){
            printf("%lld ", mat[k-1][i]);
        }
        printf("\n");
        return ;
    }
    
    //work on idx-1, idx.
    Heap h = init(k+1);
    for(int i=0;i<k; i++){
        for(int j=0;j<k; j++){
            ll sum = mat[idx-1][i] + mat[idx][j];
            if(h->iSize < k){
                insert_max_heap(h , sum);
            }
            else if(h->array[1] > sum){
                delete_max_heap(h);
                insert_max_heap(h , sum);
            }
            else{
                break;
            }
        }
    }

    for(int i=0;i<k; i++){
        ll x = delete_max_heap(h);
        mat[idx][k-i-1] = x;
    }    
    helper(idx+1 , k, mat );
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int k;
        scanf("%d", &k);

        ll mat[k][k];
        for(int i=0;i<k; i++){
            for(int j=0; j<k; j++){
                scanf("%lld", &mat[i][j]);
            }
        }
        //0->k-1.
        int idx = 1;
        //idx = k->stop.
        for(int i=0;i<k; i++){
            qsort(mat[i] , k , sizeof(ll) , cmpfunc);
        }
        helper(idx,k,mat);
    }
}