#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long int ElementType;

typedef struct Node
{
    ElementType Element;
    int index;
    struct Node *next;
} Node;

typedef Node *Position;
typedef Node *List;

typedef List HeadPtr;

typedef struct Hash_Table
{
    int TableSize;
    HeadPtr *TheLists;
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
    table->TheLists = (HeadPtr *)malloc(sizeof(HeadPtr) * (table->TableSize));
    for (int i = 0; i < table->TableSize; i++)
    {
        table->TheLists[i] = NULL; // Initialize all linked lists to NULL
    }
    return table;
}

Node *initializeNode(ElementType element, int index)
{
    Node *newListNode = (Node *)malloc(sizeof(Node));
    newListNode->Element = element;
    newListNode->index = index;
    newListNode->next = NULL;
    return newListNode;
}

ElementType hash(ElementType value, HashTable table)
{
    int a = table->TableSize;
    return value % a;
}

void insert(HashTable table, ElementType element, int index)
{
    if (table == NULL)
    {
        return;
    }
    int key = hash(element, table);
    Node *newNode = initializeNode(element, index);

    // Check if previous element exists in the hash table
    int prev_key = hash(element - 1, table);
    if (table->TheLists[prev_key] != NULL) {
        // Prepend to the linked list at the key for the previous element
        newNode->next = table->TheLists[prev_key];
        table->TheLists[prev_key] = newNode;
    } else {
        // Previous element not found, insert at the beginning of the current key list
        newNode->next = table->TheLists[key];
        table->TheLists[key] = newNode;
    }
}
void printTable(HashTable table)
{
   

    for (ElementType i = 0; i <11; i++)
    {
        List list = table->TheLists[i];
       
        while (list != NULL)
        {
            printf("%lld ", list->Element);
            list = list->next;
        }
        printf("\n");
    }

    
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
// ... other functions like printTable, find, etc. (not modified for brevity)

int main() {
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
        insert(table, book[i], i); // Insert element and its index
    }
     printTable(table);

    // ... (your code for finding longest increasing subsequence) ...

    return 0;
}
