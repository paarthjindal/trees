#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    int swapper;

    scanf("%d %d",&n , &swapper);

    int arr[n];
    int prev = -100;
    int sorted = 1;
    int maxx = -1;
    int idx_unsorted = -1;
    int max_idx  = -1;

    for(int i=0;i<n; i++){
        scanf("%d", &arr[i]);
        if(prev > arr[i]){
            sorted = 0;
            if(prev > maxx){
                maxx = prev;
                max_idx = i-1;
            }
        }
        
        prev =arr[i];
    }
    if(sorted == 1){
        printf("0\n");
        return 0;
    }
    if(maxx < swapper || max_idx == 0){
        printf("-1\n");
        return 1;
    }
    //swapper ki value should be greater tham arr[max_idx-1] & less than arr[max_idx+1]
    int count = 0;
 
    for(int i=0;i<max_idx; i++){
        if(swapper <= arr[max_idx+1] && swapper>=arr[max_idx-1]){
    
            break;
        }
        if(swapper > arr[max_idx+1]){
            printf("-1\n");
            return 0;
        }
        //printf("%d ", i);
        if(swapper > arr[i]){
            continue;
        }
        else{
            int temp = arr[i];
            arr[i] = swapper;
            swapper = temp;
            count+=1;
            if(i>0 && arr[i] < arr[i-1]){
                printf("-1\n");
                return 0;
            }
            
        }
    }
    if((swapper <= arr[max_idx+1] && swapper>=arr[max_idx-1]) == 0){
        printf("-1\n");
        return 0;
    }
    int temp = arr[max_idx];
    arr[max_idx] = swapper;
    swapper = temp;
    count+=1;
    prev = -10000;
    for(int i=0;i<n; i++){
        if(prev > arr[i]){
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n", count);
    // int count = 0;
    // int ele_unsorted = arr[idx_unsorted];
    // swapper ki value should be greater tham arr[idx_unsorted-1] & less than arr[idx_unsorted+1]
    //printf("%d %d\n", ele_unsorted , idx_unsorted);
    // int i=0;
    // while(i<idx_unsorted && (swapper>=arr[idx_unsorted-1] && swapper<=arr[idx_unsorted+1])==0 && swapper<=arr[idx_unsorted+1]){
    //     if(swapper < arr[i]){
    //         int temp = arr[i];
    //         arr[i] = swapper;
    //         swapper = temp;
    //         i+=1;
    //     }
    //     else{
    //         i+=1;
    //     }
    // }
    // printf("%d->%d",i, swapper );
}