#include<stdio.h>
#include<stdlib.h>
#include "./heap.h"
Heap* create_heap(int n)
{
    Heap* h=(Heap*)malloc(sizeof(Heap));
    h->arr=(int *)malloc(sizeof(int)*(n+1));
    h->count=0;
    h->arr[0]=-1;
    return h;
}
void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
    return;
}
void heapify(Heap* h)
{
    int p_ind=h->count/2;
    int t=h->count; 
    while(p_ind>0 && h->arr[t]<h->arr[p_ind])
    {
        swap(&h->arr[p_ind],&h->arr[t]);
        t=t/2;
        p_ind=p_ind/2;
    }
}
void insert(Heap* h,int val)
{
    ++h->count;
    if(h->count==0)
    {
        h->arr[1]=val;
        return;
    }
    h->arr[h->count]=val;
    heapify(h);
    return;
}
int extractMin(Heap* h)
{
    if(h->count>1)
    {
        swap(&h->arr[1],&h->arr[h->count--]);
        for(int i=1;i<=h->count;)
        {
            if(2*i<h->count)
            {
                if(h->arr[i]>h->arr[2*i] || h->arr[i]>h->arr[2*i+1])
                {
                    if(h->arr[2*i]<h->arr[2*i+1])
                    {
                       swap(&h->arr[i],&h->arr[2*i]);
                       i=2*i;
                    }
                    else
                    {
                       swap(&h->arr[i],&h->arr[2*i+1]);
                       i=2*i+1;
                    }
                }
                else
                {
                    break;
                }
            }
            else if(2*i==h->count)
            {
                if(h->arr[i]>h->arr[2*i])
                     swap(&h->arr[i],&h->arr[2*i]);
                break;
            }
            else
            {
                break;
            }
        }
        return h->arr[h->count+1];
    }
    else if(h->count==1)
    {
        return h->arr[h->count--];
    }
    else
    {
        return 0;
    }

}
void print_smallest_derangement(Heap* h,int* a)
{
    int n=h->count;
    int flag=0;
    int* derangement=(int*)malloc(sizeof(int)*n);
    int i=0;
    while(h->count!=0)
    {
        derangement[i]=extractMin(h);
        if(flag==1)
        {
            flag=0;
            swap(&derangement[i],&derangement[i-1]);
        }
        if(derangement[i]==a[i])
        {
            if(i==n-1)
            {
                swap(&derangement[i],&derangement[i-1]);
            }
            else
            {
                flag=1;
            }
        }
        i++;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",derangement[i]);
    }
    printf("\n");
    return;
}
