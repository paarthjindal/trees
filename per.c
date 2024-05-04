#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int getpivot(int *a, int n1)
{
    int center = (n1 - 1) / 2;
    if (a[0] > a[center])
        swap(&a[0], &a[center]);
    if (a[0] > a[n1 - 1])
        swap(&a[0], &a[n1 - 1]);
    if (a[center] > a[n1 - 1])
        swap(&a[center], &a[n1 - 1]);

    swap(&a[n1 - 2], &a[center]);
    return a[n1 - 2];
}

void quicksort(int *arr, int n)
{
    if (n > 3)
    {
        int pivot = getpivot(arr, n);
        // printf("%d\n",pivot);
        int i = 0, j = n - 2;
        while (1)
        {
            while (arr[++i] < pivot)
            {
            }
            while (arr[--j] > pivot)
            {
            }
            if (i < j)
            {
                swap(&arr[i], &arr[j]);
            }
            else
                break;
        }
        swap(&arr[i], &arr[n - 2]);
        quicksort(arr, i);
        quicksort(&arr[i + 1], n - i - 1);
    }
    else if (n == 3)
    {
        if (arr[0] > arr[1])
            swap(&arr[0], &arr[1]);
        if (arr[0] > arr[n - 1])
            swap(&arr[0], &arr[n - 1]);
        if (arr[1] > arr[n - 1])
            swap(&arr[1], &arr[n - 1]);
    }
    else if (n == 2)
    {
        if (arr[0] > arr[1])
            swap(&arr[0], &arr[1]);
    }
}

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int x = 0; x < n; x++)
    {
        int a;
        scanf("%d", &a);
        int arr[a];
        for (int y = 0; y < a; y++)
        {
            scanf("%d", &arr[y]);
        }
        quicksort(arr, a);
        int h = 1;
        for (int y = 1; y < a; y++)
        {
            if (arr[y] != arr[y - 1])
            {
                arr[h++] = arr[y];
            }
        }
        int first = 0, ans = 0;
        for (int y = 0; y < h; y++)
        {
            while (arr[y] - arr[first] >= a)
            {
                first++;
            }
            ans = max(ans, y - first + 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}