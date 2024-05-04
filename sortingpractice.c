#include <stdio.h>

void swap(int * a,int *b)
{ 
    int temp = *a;
    *a = *b;
    *b = temp;
}

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
int partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=low;
    for(int j=low;j<=high;j++)
    {
        if(arr[j]<pivot)
        {
            swap(&arr[i],&arr[j]);
            i++;
        }
    }
    swap(&arr[i],&arr[high]);
    return i;
}

void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int part=partition(arr,low,high);
        quicksort(arr,low,part-1);
        quicksort(arr,part+1,high);
    }
}
int quickselect(int arr[],int low,int high,int k)
{
    if (low<high)

    {
        int part=partition(arr,low,high);
        if(part+1==k)
        {
            return arr[part];
        }
        if(part+1>k)
        {
            return quickselect(arr,low,part-1,k);
        }
        else
        {
            return quickselect(arr,part+1,high,k);
        }       
    }
    
}

void heapify(int arr[], int N, int i)
{
    // Find largest among root,
    // left child and right child

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int left = 2 * i + 1;

    // right = 2*i + 2
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < N && arr[left] > arr[largest])

        largest = left;

    // If right child is larger than largest
    // so far
    if (right < N && arr[right] > arr[largest])

        largest = right;

    // Swap and continue heapifying
    // if root is not largest
    // If largest is not root
    if (largest != i) {

        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int N)
{

    // Build max heap
    for (int i = N / 2 - 1; i >= 0; i--)

        heapify(arr, N, i);

    // Heap sort
    for (int i = N - 1; i >= 0; i--) {

        swap(&arr[0], &arr[i]);

        // Heapify root element
        // to get highest element at
        // root again
        heapify(arr, i, 0);
    }
}

void countsort(int arr[],int n)
{
    int max =arr[0];
    for (int i = 0; i < n; i++)
    {
      if (arr[i] > max)
      {
        max = arr[i];
      }
    }   
    int a[max+1];
    for (int i = 0; i < max+1; i++)
    {
            a[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        a[arr[i]]++;
    }
    for (int i = 1; i < max+1; i++)
    {
        a[i]=a[i]+a[i-1];
    }
    int ans[n];
    for (int i = n-1; i >= 0; i--)
    {
        ans[a[arr[i]]-1]=arr[i];
        a[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i]=ans[i];
    }
    
    
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // quicksort(arr,0,n-1);
    int k=2;
    int f=quickselect(arr,0,n-1,k);
    printf("%d\n",f);
    // countsort(arr,n);
    // for(int i=0; i<n; i++)
    // {
    //     printf("%d ", arr[i]);
    // }
    
    return 0;
}