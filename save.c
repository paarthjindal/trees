#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

typedef long long int ElementType;

typedef struct Node
{
    ElementType Element;
    int index;
    struct Node *next;
    int length;
} Node;

typedef Node *Position;

typedef Node *List;

typedef struct Hash_Table
{
    int TableSize;
    List *arr;

} Hash_Table;

typedef Hash_Table *HashTable;

HashTable initializeTable(int TableSize)
{
    if (TableSize < 0)
    {
        printf("invalid table size");
    }
    HashTable table = (HashTable)malloc(sizeof(Hash_Table));
    if (table == NULL)
    {
        printf("failed to allocate memory");
        exit(-1);
    }
    table->TableSize = TableSize;
    table->arr = (List *)malloc(sizeof(List) * (table->TableSize));
    int a = table->TableSize;
    for (int i = 0; i < a; i++)
    {

        table->arr[i] = NULL;
    }
    return table;
}

Node *initializeNode(ElementType element)
{
    Node *newListNode = (Node *)malloc(sizeof(Node));
    newListNode->Element = element;
    newListNode->next = NULL;
    newListNode->index = 0;
    newListNode->length = 0;
    return newListNode;
}
ElementType hash(ElementType value, HashTable table)
{
    int a = table->TableSize;
    return value % a;
}
Position find(int element, HashTable table);
void insert(HashTable table, Node *newNode)
{
    if (table == NULL)
    {
        return;
    }

    long long int a = newNode->Element;
    int index1 = hash(a, table);
    int index2 = hash(a - 1, table);

    Node *temp2 = table->arr[index2];
    if (temp2 == NULL)
    {
        table->arr[index1] = newNode;
        table->arr[index1]->length = 1;
        return;
    }
    else
    {
        table->arr[index1] = newNode;

        table->arr[index1]->length = temp2->length + 1;
    }
}

Position find(int element, HashTable table)
{
    if (table == NULL)
    {
        return NULL;
    }

    int key = hash(element, table);
    List list = table->arr[key];
    if (list == NULL)
    {
        return NULL;
    }
    while (list != NULL)
    {
        if (list->Element == element)
        {
            return list;
        }
        list = list->next;
    }
    return NULL;
}

void printTable(HashTable table)
{

    for (ElementType i = 10; i < 20; i++)
    {
        List list = table->arr[i];

        while (list != NULL)
        {

            printf("%lld ", list->length);
            list = list->next;
        }
        printf("\n");
    }
}
void swap(ElementType *a, ElementType *b)
{
    ElementType temp = *a;
    *a = *b;
    *b = temp;
}

bool is_prime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int gennextprime(int n)
{
    if (n <= 1)
    {
        return 2;
    }

    while (true)
    {
        if (is_prime(n))
        {
            return n;
        }
        n++;
    }
}
int maximum(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
ElementType findmax(HashTable table,int max)
{
    if (table == NULL)
    {
        return 0;
    }
    // int key = hash(max, table);
    // List list = table->arr[key];
    // if (list == NULL)
    // {
    //     return 0;
    // }
    // while (list!= NULL)
    // {
    //     return list->Element;
    // }
    // return 0;
    for (int i = 0; i < table->TableSize; i++)
    {
        Node* temp=table->arr[i];
        if(temp==NULL)
        {
            continue;
        }
        else
        {
            if(temp->length==max)
            {
                return temp->Element;
            }
            else
            {
                continue;
            }
        }

    }
    
}
int main()
{
    HashTable table;
    int size = 2 * 100000;
    int prime;
    prime = gennextprime(size);
    table = initializeTable(prime);

    int n;
    scanf("%d", &n);
    ElementType book[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &book[i]);
        int key = hash(book[i], table);

        Node *head = initializeNode(key);
        head->index = i;
        head->next = NULL;
        insert(table, head);
    }
    if(n==1)
    {
        printf("1\n");
        printf("0\n");
        return 0;
    }
    int count = 1;
    int max = 1;
    for (int i = 0; i < table->TableSize; i++)
    {
        Node *temp = table->arr[i + 1];
        Node *prev = table->arr[i];
        if (prev == NULL)
        {
           
            count = 1;
            continue;
        }
        else
        {

            if (temp == NULL)
            {
                max = maximum(count, max);
                count = 1;
                continue;
            }
            else
            {
                if (temp->length == prev->length + 1)
                {
                    count++;
                }
                else
                {
                    max = maximum(count, max);
                    count = 1;
                    continue;
                }
            }
        }
    }
    printf("%d\n", max);
    
    ElementType final= findmax(table,max);
    // printf("%lld\n", final);
    ElementType y=final-max+1;
    // printf("%lld\n",y);
    for (int i = 0; i < max; i++)
    {
        
        Node* test=find(y,table);
        if(test!=NULL)
        {
        printf("%d ", test->index);
        y=y+1;
        }
        
    }
    

    // printTable(table);

    return 0;
}