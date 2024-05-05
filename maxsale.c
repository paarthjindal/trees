#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *createnode(int d)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = d;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node* insert(node* root,int value)
{
    if(root==NULL)
    {
        return createnode(value);
    }
    if(value<root->data)
    {
        root->left=insert(root->left,value);
    }
    else
    {
        root->right=insert(root->right,value);
    }
    return root;
}

void updatevalues(node* root, int* sum) {
    if (root == NULL) {
        return;
    }
    updatevalues(root->left, sum);
    *sum += root->data;
    root->data = *sum;
    updatevalues(root->right, sum);
}

void inorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

node* modify(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
}
int main()
{
    int n;
    node* root=NULL;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        root=insert(root,arr[i]);
    }
    inorder(root);
    printf("\n");
    int sum=0;
    updatevalues(root,&sum);
    inorder(root);
    // printf("%d\n",root->data);


    return 0;
}
