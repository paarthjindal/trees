#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct stnode
{
    int distance;
    int count;
    struct stnode *next;
} stnode;
typedef stnode *Node;
typedef struct sthash
{
    Node *node;
} sthash;
typedef sthash *Hash;
typedef struct heap
{
    int *arr;
    int size;
    int capacity;
} heap;
typedef heap *heap2;
heap2 createheap2(int size)
{
    heap2 h = (heap2)malloc(sizeof(heap));
    h->capacity = size + 1;
    h->size = 0;
    h->arr = (int *)malloc(sizeof(int) * size + 1);

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

void insert2(heap *h, int value)
{
    if (h->size < h->capacity)
    {
        h->arr[h->size] = value;
        inserthelp(h, h->size);
        (h->size)++;
    }
}

int extractmin(heap *h)
{
    if (h->size == 0)
    {
        return 0;
    }
    int min = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    heapify(h, 0);
    return min;
}
Node createnode(int count, int dist)
{
    Node n = (Node)malloc(sizeof(stnode));
    n->count = count;
    n->distance = dist;
    n->next = NULL;
    return n;
}
Hash createhash(int n)
{
    Hash h = (Hash)malloc(sizeof(sthash));
    h->node = (Node *)malloc(sizeof(Node) * (n + 1));
    return h;
}
int gethash(long long int a)
{
    return a % 10000000;
}
Hash insert(Hash h, int data, int distance)
{
    Node temp = h->node[gethash(distance)];
    if (temp == NULL)
    {
        h->node[gethash(distance)] = createnode(data, distance);
        return h;
    }
    else
    {
        // h->node[gethash(distance)]->count++;
        Node new=createnode(data,distance);
        new->next=h->node[gethash(distance)];
        h->node[gethash(distance)]=new;
        return h;
    }
}

int search(Hash h, int data)
{
    int g = gethash(data);
    Node temp = h->node[g];
    // printf("temp %d %d\n",temp->distance,temp->count);
    while (temp != NULL)
    {
        if (temp->distance == data)
        {
            return temp->count;
        }
        temp = temp->next;
    }
    return 0;
}

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int n;
    int d;
    int k;
    int p;
    scanf("%d", &n);
    scanf("%d", &k);
    scanf("%d", &d);
    scanf("%d", &p);
    heap2 h = createheap2(n);
    int depth[n+1];
    Hash h2 = createhash(10000000);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &depth[i]);
    }
    depth[n] = d;
    for (int i = 0; i < n; i++)
    {
        int curr;
        scanf("%d", &curr);
        insert(h2, curr, depth[i]);
        // printf("%d %d\n",depth[i],curr);
    }
    insert(h2, 0, d);
    qsort(depth, n, sizeof(int), cmp);
    long long int ans = 0;
    long long int covered = k;
    for (int i = 0; i <= n; i++)
    {
        int temp = depth[i];
       
        if (covered >= temp)
        {
            // printf("%d ",temp);
            int k = search(h2, temp);
            // printf("k=%d\n",k);
            insert2(h, k);
        }
        else
        {
            int check = 0;
            while (h->size != 0)
            {
                covered += p;
                ans += extractmin(h);
                if (covered >= temp)
                {
                    check = 1;
                    int k = search(h2, temp);
                    insert2(h, k);
                    break;
                }
            }
            if (check == 0)
            {
                printf("-1 %lld\n", covered);
                return 0;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}