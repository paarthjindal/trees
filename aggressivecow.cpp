#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <stdlib.h>
#include <stdbool.h>
void merge(int arr[],int low,int mid,int high)
{
    int n1=mid-low+1;
    int n2=high-mid;
    int arr1[n1];
    int arr2[n2];
    for(int i=0;i<n1;i++)
    {
        arr1[i]=arr[low+i];
    }
    for(int i=0;i<n2;i++)
    {
        arr2[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=low;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<=arr2[j])
        {
            arr[k]=arr1[i];
            i++;
        }
        else
        {
            arr[k]=arr2[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=arr2[j];
        j++;
        k++;
    }
}

void mergesort(int arr[],int low,int high)
{
    if(low<high)
    {
        int middle=low+(high-low)/2;
        mergesort(arr,low,middle);
        mergesort(arr,middle+1,high);
        merge(arr,low,middle,high);
    }
}
bool check(int arr[],int a,int b,int cows)
{
   cows--;
   int sum=arr[0]+a;
   for (int i = 1; i < b; i++)
   {
    if(arr[i]>=sum)
    {
        cows--;
        if(cows==0)
        {
            break;
        }
        sum=arr[i]+a;
    } 
   }
   if(cows==0)
   {
    return true;
   }
   else
   {
    return false;
   }
   
}
using namespace std;
int main()
{
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        int n,c;
        cin>>n>>c;
        int arr[n];
        for (int j = 0; j < n; j++)
        {
            cin>>arr[j];
        }
        mergesort(arr,0,n-1);
        int low=1;
        int high=arr[n-1]-arr[0];
        int ans=0;
        while(low<=high)
        {
            int middle=low+(high-low)/2;
            // printf("%d ",middle);
            if(check(arr,middle,n,c))
            {
                // printf("hello\n");
                ans=middle;
                low=middle+1;

            }
            else
            {
                high=middle-1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}