#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long int ElementType;

typedef struct Node
{
    ElementType Element;
    int index;
    struct Node *next;
    int length;
} Node;

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
        exit(-1);
    }
    HashTable table = (HashTable)malloc(sizeof(Hash_Table));
    if (table == NULL)
    {
        printf("failed to allocate memory");
        exit(-1);
    }
    table->TableSize = TableSize;
    table->arr = (List *)malloc(sizeof(List) * (table->TableSize));
    for (int i = 0; i < table->TableSize; i++)
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
    newListNode->index = -1; // Initialize index to -1
    newListNode->length = 0;
    return newListNode;
}

int hash(ElementType value, HashTable table)
{
    return labs(value) % table->TableSize;
}

void insert(HashTable table, Node *newNode, int index)
{
    int hashValue = hash(newNode->Element, table);
    if (table->arr[hashValue] == NULL)
    {
        table->arr[hashValue] = newNode;
        newNode->index = index; // Update index if slot is empty
    }
    else
    {
        Node *temp = table->arr[hashValue];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->index = index; // Update index for new node
    }
}

int main()
{
    HashTable table;
    int size = 2 * 100000;
    int prime = size; // Set prime to size
    table = initializeTable(prime);

    int n;
    scanf("%d", &n);
    ElementType book[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &book[i]);
        Node *newNode = initializeNode(book[i]);
        insert(table, newNode, i);
    }

    int count = 1;
    int max = 1;

    for (int i = 0; i < table->TableSize; i++)
    {
        Node *temp = table->arr[i];
        Node *prev = NULL;

        while (temp != NULL)
        {
            if (prev != NULL && temp->Element == prev->Element + 1)
            {
                count++;
            }
            else
            {
                max = (count > max) ? count : max;
                count = 1;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    printf("%d\n", max);

    for (int i = 0; i < table->TableSize; i++)
    {
        Node *temp = table->arr[i];

        while (temp != NULL)
        {
            if (temp->length == max)
            {
                printf("%d ", temp->index);
            }
            temp = temp->next;
        }
    }

    return 0;
}
