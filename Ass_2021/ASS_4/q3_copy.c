#include<stdio.h>
#include<stdlib.h>

typedef long long int ll;

const int N = 300009;


int cmpfunc (const void * a, const void * b)
{
    if( *(long long int*)a - *(long long int*)b < 0 )
        return 1;
    if( *(long long int*)a - *(long long int*)b > 0 )
        return -1;
    return 0;
}


int main(){
    
    ll n, k;
    
    scanf("%lld %lld", &n, &k);
    ll arr[n];
	for(int i = 0; i < n; ++i)
        scanf("%lld", &arr[i]);
	
	ll sum = 0;
	ll sum_subset[n-1];
    ll idx = 0;
	for(int i = n - 1; i >= 0; --i){
	    sum += arr[i];
	    if(i > 0){
            sum_subset[idx] = sum;
         idx+=1;
        }
         
	}
	
	ll res = sum;
	
	qsort(sum_subset , n-1 , sizeof(ll) , cmpfunc);
	
	
	for(int i = 0; i < k - 1; ++i)
	    res += sum_subset[i];
	    
	printf("%lld", res);
	return 0;
}