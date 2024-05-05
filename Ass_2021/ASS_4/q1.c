#include<stdio.h>
#include<stdlib.h>

typedef long long int ll;
int cmpfunc(const void* a , const void*b){
    return (*(ll*)a - *(ll*)b);
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        ll n;
        scanf("%lld", &n);

        ll arr[n];

        for(ll i=0;i<n; i++){
            scanf("%lld", &arr[i]);
        }

        qsort(arr , n , sizeof(ll) , cmpfunc);
        // for(ll i=0;i<n; i++){
        //     printf("%lld ", arr[i]);
        // }
        // prllf("\n");
        ll a[n];

        ll prev_ele = arr[0];
        a[0]=1;
        ll curr_idx = 0;
        for(ll i=1;i<n; i++){
            if(arr[i] == prev_ele){
                a[curr_idx]+=1;
            }
            else{
                curr_idx+=1;
                a[curr_idx] =1;
                prev_ele = arr[i];
            }
        }
        // for(int i=0;i<curr_idx+1; i++){
        //     printf("%d ", a[i]);
        // }
        // printf("\n");
        //size of array curr_idx+1.
        ll maxx = -1;
        for(ll i=0;i<curr_idx+1; i++){
            if(a[i] > maxx){
                maxx = a[i];
            }
        }
        //printf("maxx->%d , y->%d\n", maxx, y);
        ll y=0;
        for(ll i=0;i<curr_idx+1 ; i++){
            if(a[i] == maxx){
                y+=1;
            }
        }
        // printf("maxx->%lld , y->%lld\n", maxx, y);
        if(maxx==1){
            printf("%lld\n" , n);
            continue;
        }
        ll ans = (n- (maxx*y))/(maxx-1) + y-1;
        printf("%lld\n", ans);
    }
}