#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node Node;
typedef struct Node *Nodeptr;

struct Node
{
    int val;
    Nodeptr right;
    Nodeptr left;
};

Nodeptr init(int x)
{
    Nodeptr head = (Nodeptr)malloc(sizeof(Node));
    head->right = NULL;
    head->left = NULL;
    head->val = x;
    return head;
}

Nodeptr createTree(int *arr, int n)
{

    Nodeptr v[n];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != -1)
        {
            v[i] = init(arr[i]);
        }
    }
    int idx = 0;
    while (idx < n)
    {
        if (arr[idx] == -1)
        {
            idx += 1;
            continue;
        }
        if (2 * idx + 1 < n && arr[2 * idx + 1] != -1)
        {
            v[idx]->left = v[2 * idx + 1];
        }
        if (2 * idx + 2 < n && arr[2 * idx + 2] != -1)
        {
            v[idx]->right = v[2 * idx + 2];
        }
        idx += 1;
        ;
    }
    return v[0];
}

void inorder(Nodeptr head)
{
    if (head == NULL)
    {
        return;
    }
    inorder(head->left);
    printf("%d", head->val);
    inorder(head->right);
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
    Nodeptr head = createTree(arr, n);
    inorder(head);
}