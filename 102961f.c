#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct node
{
    int start;
    int end;
}node;

void merge(node**arr,int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    node*L=(node*)malloc(n1*sizeof(node));
    node*R=(node*)malloc(n2*sizeof(node));
    for (int i = 0; i < n1; i++)
    {
        L[i].end=arr[l+i]->end;
        L[i].start=arr[l+i]->start;

    }
    for (int i = 0; i < n2; i++)
    {
        R[i].end=arr[m+1+i]->end;  
        R[i].start=arr[m+1+i]->start;

    }
    int i=0,j=0,k=l;
    while(i<n1&&j<n2)
    {
        if(L[i].end<=R[j].end)
        {
            arr[k]->end=L[i].end;
            arr[k]->start=L[i].start;
            i++;
        }
        else
        {
            arr[k]->end=R[j].end;
            arr[k]->start=R[j].start;
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]->end=L[i].end;
        arr[k]->start=L[i].start;
        k++;
        i++;
    }
    while (j<n2)        
    {
        arr[k]->end=R[j].end;
        arr[k]->start=R[j].start;
        k++;
        j++;
    }   
}

void mergesort(node**arr,int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int maximum(int a,int b)
{
    if(a>=b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    node**arr=(node**)malloc(n*sizeof(node*));
    for (int i = 0; i < n; i++)
    {
        arr[i]=(node*)malloc(sizeof(node));
    }
    for (int i = 0; i < n; i++)
    {
        int a,b;
        scanf("%d", &a);
        scanf("%d", &b);
        arr[i]->start=a;
        arr[i]->end=b;
    }
    mergesort(arr,0,n-1);
    int max=0;
    int sum=1;
    for (int i = 0; i < n-1; i++)
    { 
        if(arr[i]->end<=arr[i+1]->start)
        {
            sum++;
        }
        else
        {
            max=maximum(max,sum);
            sum=1;
        }    
    }
    printf("%d\n",max);
   return 0;
}