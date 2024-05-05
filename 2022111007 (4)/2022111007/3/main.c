#include<stdio.h>
#include "./heap.h"
int main()
{
    int n;
    scanf("%d",&n);
    long int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%ld",&a[i]);
    }
    printf("%d\n",maxKnobs(a,n));
    return 0;
}