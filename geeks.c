#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

typedef struct node
{
    int data;
    int value;
} node;

typedef struct heap
{
    node **arr;
    int size;
    int capacity;
} heap;

heap *create_heap(int size)
{
    heap *h = (heap *)malloc(sizeof(heap));
    h->size = 0;
    h->capacity = size;
    h->arr = (node **)malloc(sizeof(node *) * size);
    for (int i = 0; i < size; i++)
    {

        h->arr[i] = (node *)malloc(sizeof(node));
    }
    return h;
}

void heapify(heap *h, int i);
void inserthelp(heap *h, int i);

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
    if (left != -1 && h->arr[left]->data < h->arr[min]->data)
    {
        min = left;
    }
    if (right != -1 && h->arr[right]->data < h->arr[min]->data)
    {
        min = right;
    }
    if (min != index)
    {
        node *temp = h->arr[index];
        h->arr[index] = h->arr[min];
        h->arr[min] = temp;
        heapify(h, min);
    }
}

void insert(heap *h, int value, int x)
{
    if (h->size == h->capacity)
    {
        return;
    }
    int a = abs(value - x);
    if (a == 0)
    {
        return;
    }
    h->arr[h->size]->data = a;
    h->arr[h->size]->value = value;
    inserthelp(h, h->size);
    h->size++;
}
void inserthelp(heap *h, int i)
{
    if (i == 0)
    {
        return;
    }
    int parent = (i - 1) / 2;
    if (h->arr[i]->data < h->arr[parent]->data)
    {
        node *temp = h->arr[i];
        h->arr[i] = h->arr[parent];
        h->arr[parent] = temp;
        inserthelp(h, parent);
    }
    return;
}
void heapsort(heap *h)
{
    
}
node *extractmin(heap *h)
{
    if (h->size == 0)
    {
        return NULL;
    }
    node *min = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    heapify(h, 0);
    return min;
}
void printheap(heap *h)
{
    int i;
    for (i = 0; i < h->size; i++)
    {
        printf("%d ", h->arr[i]->data);
    }
    printf("\n");
}

void findk(heap *h, int k)
{
    for (int i = 0; i < k; i++)
    {
        node *min = extractmin(h);
        printf("%d ", min->value);
    }
}
int main()
{
    int n, k, x;
    scanf("%d%d%d", &n, &k, &x);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    heap *h = create_heap(n);

    for (int i = 0; i < n; i++)
    {
        insert(h, arr[i], x);
    }

    if (k > h->size)
    {
        printf("Not enough elements in the heap to find %d closest elements.\n", k);
    }
    else
    {
        findk(h, k);
    }

    return 0;
}
