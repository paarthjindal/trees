#include<stdio.h>
#include "./heap.h"
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    Heap* h=create_heap(n);
    for(int i=0;i<n;i++)
    {
       scanf("%d",&a[i]);
       insert(h,a[i]);
    }
    print_smallest_derangement(h,a);    
    return 0;
}