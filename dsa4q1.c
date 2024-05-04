#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
typedef struct node
{
    int minrequire;
    int valuechange;
    int index;
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
    h->arr = (node **)malloc(sizeof(node*) * size);
    for (int i = 0; i < size; i++)
    {
        // h->arr[i] = (node *)malloc(sizeof(node));
        h->arr[i]=NULL;
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
    if (left != -1 && h->arr[left]->minrequire < h->arr[min]->minrequire)
    {
        min = left;
    }
    if (right != -1 && h->arr[right]->minrequire < h->arr[min]->minrequire)
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

void insert(heap *h, int a, int b, int c)
{
    if (h->size == h->capacity)
    {
        return;
    }

    node *new_node = (node *)malloc(sizeof(node));
    new_node->minrequire = a;
    new_node->valuechange = b;
    new_node->index = c;

    h->arr[h->size] = new_node;
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
    if (h->arr[i]->minrequire < h->arr[parent]->minrequire)
    {
        node *temp = h->arr[i];
        h->arr[i] = h->arr[parent];
        h->arr[parent] = temp;
        inserthelp(h, parent);
    }
    return;
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
        printf("%d ", h->arr[i]->minrequire);
    }
    printf("\n");
}

void delete(heap *h, int val)
{
    for (int i = 0; i < h->size; i++)
    {
        if (h->arr[i]->index == val)
        {
            h->arr[i] = h->arr[h->size - 1];
            h->size--;
            heapify(h, i);
            break;
        }
    }
}

int main()
{
    int n;
    int k;
    scanf("%d%d", &n, &k);
    int arr[n];
    int arr1[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
        sum = sum + arr1[i];
    }
    heap *h = create_heap(n);
    for (int i = 0; i < n; i++)
    {
        insert(h, arr[i], arr1[i], i);
    }
    // printheap(h);
    // delete(h,2);
    // printheap(h);

    
      int initial = k;
    bool all_chambers_visited = true;

    while (h->size != 0 && initial >= 0 && all_chambers_visited)
    {
        bool chamber_visited = false;
        for (int i = 0; i < h->size; i++)
        {
            node *temp = h->arr[i];
            if (temp->minrequire <= initial && (temp->valuechange + initial) >= 0)
            {
                delete(h, i);
                initial = initial + temp->valuechange;
                chamber_visited = true;
                break;
            }
        }
        if (!chamber_visited)
        {
            all_chambers_visited = false;
        }
    }

    if (all_chambers_visited)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    // Free allocated memory for the heap
    for (int i = 0; i < h->size; i++)
    {
        free(h->arr[i]);
    }
    free(h->arr);
    free(h);

    return 0;
    return 0;
}