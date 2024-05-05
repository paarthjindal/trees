#include<stdio.h>
#include<stdlib.h>

int is_sorted(int* arr , int n){
    int prev = arr[0];

    for(int i=1; i<n; i++){
        if(arr[i] < prev){

            return 0;
        }
        prev = arr[i];
    }
    return 1;
}

// void printf_array(int *arr , int n){
//     for(int i=0;i<n; i++){
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }
int main(){
    int n,swapper;

    scanf("%d %d", &n, &swapper);

    int arr[n];
    for(int i=0;i<n; i++){
        scanf("%d", &arr[i]);
    }

    if(is_sorted(arr , n) == 1){
        printf("0\n");
        return 0;
    }

    int count = 0;
    int i=0;
    int j = -1;

    for(int i=0;i<n; i++){
        if(swapper < arr[i]){
            j = i;
            break;
        }
        
    }

    if( j==-1){
        printf("-1\n");
        return 0;
    }

    int temp = arr[j];
    arr[j] = swapper;
    swapper = temp;
    count+=1;

    if(is_sorted(arr , n) == 1){
        printf("1\n");
        return 0;
    }

    for(int i = j+1; i<n; i++){
        //printf_array(arr , n);
       // printf("%d %d\n", swapper);
        if(arr[i] > swapper){
            int temp = arr[i];
            arr[i] = swapper;
            swapper = temp;
            count+=1;
            if(is_sorted(arr , n) == 1){
                printf("%d\n", count);
                return 0;
            }
        }
    }

    // if(is_sorted(arr , n) == 1){
    //     printf("%d\n", count);
    //     return 0;
    // }
    // else{
    //     printf("-1\n");
    //     return 0;
    // }
    printf("-1\n");
}