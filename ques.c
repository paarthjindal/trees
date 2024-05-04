#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

typedef struct heap
{
    int *arr;
    int size;
    int capacity;
} heap;

void heapify(heap *h, int i);
void inserthelp(heap *h, int i);
heap *createheap(int capacity, int arr[])
{
    heap *h = (heap *)malloc(sizeof(heap));
    h->capacity = capacity;
    h->size = 0;
    h->arr = (int *)malloc(capacity * sizeof(int));
    int i;
    for (i = 0; i < capacity; i++)
    {
        h->arr[i] = arr[i];
    }
    h->size = i;
    int n = i;
    i = (n - 2) / 2;
    while (i >= 0)
    {
        heapify(h, i);
        i--;
    }
    return h;
}
void heapify(heap *h, int i)
{
    int index = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left >= h->size || left < 0)
    {
        left = -1;
    }
    if (right >= h->size || right < 0)
    {
        right = -1;
    }
    int min = index;
    if (left != -1 && h->arr[left] < h->arr[min])
    {
        min = left;
    }
    if (right != -1 && h->arr[right] < h->arr[min])
    {
        min = right;
    }
    if (min != index)
    {
        int temp = h->arr[index];
        h->arr[index] = h->arr[min];
        h->arr[min] = temp;
        heapify(h, min);
    }
}

void insert(heap *h, int value)
{
    if (h->size < h->capacity)
    {
        h->arr[h->size] = value;
        inserthelp(h, h->size);
        (h->size)++;
    }
}
void inserthelp(heap *h, int i)
{
    int parent = (i - 1) / 2;
    if (h->arr[i] < h->arr[parent])
    {
        int temp = h->arr[i];
        h->arr[i] = h->arr[parent];
        h->arr[parent] = temp;
        inserthelp(h, parent);
    }
}
int extractmin(heap *h)
{
    if (h->size == 0)
    {
        return -100;
    }
    int min = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    heapify(h, 0);
    return min;
}

void heapsort(heap *h)
{
    int i;
    for (i = h->size - 1; i >= 0; i--)
    {
        int temp = h->arr[0];
        h->arr[0] = h->arr[i];
        h->arr[i] = temp;
        h->size--;
        heapify(h, 0);
    }
}
int minsum(heap *h)
{
    int count = h->size;
    int sum = 0;

    while (count >= 2)
    {
        int min1 = extractmin(h);
        int min2 = extractmin(h);
        // printf("%d\n",min1);
        // printf("%d\n",min2);
        sum = sum + min1 + min2;

        insert(h, min1 + min2);

        count = count - 1;
    }
    return sum;
}
void printheap(heap *h)
{
    int i;
    for (i = 0; i < h->size; i++)
    {
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    heap *h = createheap(n, arr);
    printheap(h);
    int ans = minsum(h);
    printf("%d\n", ans);

    return 0;
}