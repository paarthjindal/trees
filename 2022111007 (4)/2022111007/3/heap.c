#include<stdio.h>
#include<stdlib.h>
#include "./heap.h"
//Using min-heap for this

void swap(long int* a,long int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
    return;
}
Heap* create_heap(int n)
{
    Heap* h=(Heap*)malloc(sizeof(Heap));
    h->arr=(long int *)malloc(sizeof(long int)*(n+1));
    h->count=0;
    h->arr[0]=-1;
    h->t_exp=0;
    return h;
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
void insert(Heap* h,long int val)
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
long int extractMin(Heap* h)
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
int maxKnobs(long int* a,int n)
{
    Heap* h=create_heap(n);
    int knobs=0;
    long int temp=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<0)
        {
            if(a[i]*-1>temp)
            {
                if(h->count!=0 && a[i]>h->arr[1])
                {
                    temp=temp-extractMin(h)+a[i];
                    insert(h,a[i]);
                }
            }
            else
            {
                temp+=a[i];
                insert(h,a[i]);
                knobs++;
            }
        }
        else
        {
            temp+=a[i];
            knobs++;
        }
    }
    free(h->arr);
    free(h);
    return knobs;
}
