#include"stack.h"
#include<stdlib.h>
#include<stdio.h>


void helper(int *arr ,stackptr st , int n){
    int sum = 0;
    int first[n];
    for(int i=n-1; i>=0 ;i--){
        if(IsEmpty(st) == 1){
            first[i] = 0;
            push(st , i);
        }
        else{
            while(IsEmpty(st)==0 && arr[i]>arr[Top(st)]){
                pop(st);
            }
            if(IsEmpty(st) == 1){
                first[i] = 0;
            }
            else{
                int x=Top(st)-i+1;
                first[i] = first[Top(st)]+x;
            }
            push(st , i);
        }
    }

    for(int i=00;i<n; i++){
        printf("%d ", first[i]);
    }
    printf("\n");
}
int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    stackptr st = Intial_Stack(n);
    helper(arr , st, n);
    clearStack(st);
    int arr2[n];
    for(int i=0;i<n; i++){
        arr2[i] = arr[n-i-1];
    }
    helper(arr2 ,st,n);
}