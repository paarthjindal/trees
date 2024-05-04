#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node* createnode(int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node* createtree(int *arr, int n)
{
    node **a = (node**)malloc(n * sizeof(node*));
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != -1)
            a[i] = createnode(arr[i]);
        else
            a[i] = NULL;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != NULL)
        {
            if (2 * i + 1 < n)
                a[i]->left = a[2 * i + 1];
            if (2 * i + 2 < n)
                a[i]->right = a[2 * i + 2];
        }
    }
    node* root = a[0];
    free(a);
    return root;
}

void inorder(node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
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
    node* root = createtree(arr, n);
    inorder(root);
    return 0;
}
