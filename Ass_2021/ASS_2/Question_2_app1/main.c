#include"stack.h"
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,m;
    scanf("%d %d", &n , &m);

    ElementType arr[n];

    for(int i=0;i<n;i++){
        scanf("%lld", &arr[i]);
    }


    stackptr st = Intial_Stack(m);
    push(st, arr[0]);

    for(int i=1;i<m; i++){
        if(arr[i] < Top(st)){
            pop(st);
            push(st , arr[i]);
        }
    }
    printf("%lld ", Top(st));

    for(int i=1 ; i<=n-m; i++){

        if(Top(st) == arr[i-1]){
            pop(st);
            push(st,arr[i]);

            for(int j=i+1; j<i+m ; j++){
                if(arr[j] < Top(st)){
                    pop(st);
                    push(st , arr[j]);
                }
            }
        }
        else{
            if(Top(st) > arr[i+m-1] ){
                pop(st);
                push(st, arr[i+m-1]);
            }
        }

        printf("%lld ", Top(st));
    }
}