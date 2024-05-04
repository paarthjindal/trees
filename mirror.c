#include <stdio.h>
#include <stdlib.h> // Include this for malloc

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *newNode(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int ismirror(struct node *a, struct node *b)
{
    if (a == NULL && b == NULL)
        return 1;
    if (a == NULL || b == NULL)
        return 0;
    if (a->data != b->data)
        return 0;
    return ismirror(a->left, b->right) && ismirror(a->right, b->left);
}

int sum(struct node *a)
{
    if (a == NULL)
        return 0;
    return a->data + sum(a->left) + sum(a->right);
}

int sumtree(struct node *a, int target_sum)
{
    if (a == NULL || (a->left == NULL && a->right == NULL))
    {
        return 1;
    }
    int left_sum = sum(a->left);
    int right_sum = sum(a->right);
    if ((left_sum + right_sum + a->data == target_sum)||sumtree(a->left, target_sum)||sumtree(a->right, target_sum))
    {
        return 1;
    }
    return 0;
}

int main()
{
    node *root = newNode(8);
    root->left = newNode(5);
    root->right = newNode(4);
    root->left->left = newNode(9);
    root->left->right = newNode(7);
    root->left->right->left = newNode(1);
    root->left->right->right = newNode(12);
    root->left->right->right->right = newNode(2);
    root->right->right = newNode(11);
    root->right->right->left = newNode(3);
    int target_sum = 20;

    if (sumtree(root, target_sum))
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}
