#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void merge(long long int arr[], long long int low,long long int mid,long long int high)
{
    long long int n1=mid-low+1;
  long long   int n2=high-mid;
   long long  int arr1[n1];
   long long  int arr2[n2];
    for(long long int i=0;i<n1;i++)
    {
        arr1[i]=arr[low+i];
    }
    for(long long int i=0;i<n2;i++)
    {
        arr2[i]=arr[mid+1+i];
    }
    long long int i=0,j=0,k=low;
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

void mergesort(long long int arr[],long long int low,long long int high)
{
    if(low<high)
    {
        long long int middle=low+(high-low)/2;
        mergesort(arr,low,middle);
        mergesort(arr,middle+1,high);
        merge(arr,low,middle,high);
    }
}

int main() {
 long long  int n;
  cin >> n;
  long long int arr[n];
  for (long long int i = 0; i < n; i++)
  {
    cin >> arr[i]; 
  }
  mergesort(arr,0,n-1);
  long long int median=arr[n/2];
  long long int sum=0;
  for (long long int  i = 0; i < n; i++)
  {
    sum=sum+abs(arr[i]-median);
    // cout<<arr[i]-median<<endl;
    
  }
  cout<<sum<<endl;
  return 0;
  
  

 
  
}
