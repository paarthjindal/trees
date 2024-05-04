
#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// ------------------- Selection Sort -------------------
// Pushing minimum element to the front
void Selection_Sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(&arr[i], &arr[min_index]);
    }
}

// ------------------- Bubble Sort -------------------
// Pushing maximum element to the end
void bubble_Sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// I------------------- Insertion Sort -------------------
// Pushing element to its correct position
void insertion_Sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(&arr[j], &arr[j - 1]);
            j--;
        }
    }
}

// ------------------- Shell Sort -------------------
void shell_Sort(int arr[], int n)
{
    int gap = 1;
    while (gap < n / 3)
    {
        gap = 3 * gap + 1;
    }

    for (; gap > 0; gap /= 3)
    {
        for (int i = gap; i < n; i++)
        {
            int j = i;
            while (j - gap >= 0 && arr[j - gap] > arr[j])
            {
                swap(&arr[j], &arr[j - gap]);
                j--;
            }
        }
    }
}

// ------------------- Merge Sort -------------------
void merge(int arr[], int low, int mid, int high)
{
    if (low >= high)
        return;
    if (arr[mid] < arr[mid + 1])
        return;
    int n = high - low + 1;
    int i = low, j = mid + 1;
    int ans[n];
    int cnt = 0;
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            ans[cnt++] = arr[i];
            i++;
        }
        else
        {
            ans[cnt++] = arr[j];
            j++;
        }
    }
    while (i <= mid)
    {
        ans[cnt++] = arr[i];
        i++;
    }
    while (j <= high)
    {
        ans[cnt++] = arr[j];
        j++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = ans[i - low];
    }
}


// Recursive Merge Sort
void merge_sort(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

// Bottom Up Merge Sort
void bottom_merge_sort(int arr[], int n)
{
    for (int sz = 1; sz < n; sz *= 2)
    {
        for (int i = 0; i < n - sz; i += 2 * sz)
        {
            int low = i;
            int mid = i + sz - 1;
            int high = i + 2 * sz - 1;
            high = high < n ? high : n - 1;
            merge(arr, low, mid, high);
        }
    }
}

// ------------------- Quick Sort -------------------
int partition(int arr[], int low, int high)
{
    int pivot = low;
    int i = low, j = high;
    while (i < j)
    {
        while (i <= high - 1 && arr[i] < arr[pivot])
        {
            i++;
        }
        while (j >= low + 1 && arr[j] > arr[pivot])
        {
            j--;
        }

        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[pivot], &arr[j]);
    return j;
}

void quick_sort(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int pIndex = partition(arr, low, high);
    quick_sort(arr, low, pIndex - 1);
    quick_sort(arr, pIndex + 1, high);
}

// ------------------- Main Function -------------------
int main()
{
    int arr[] = {1, 6, 2, 5, 17, 8, 72, 3, 57, 24, 20, 95};
    int n = sizeof(arr) / sizeof(arr[0]);
    // shell_Sort(arr, n);
    // insertion_Sort(arr,n);
    // merge_sort(arr,0,n-1);
    bottom_merge_sort(arr, n);
    // quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}