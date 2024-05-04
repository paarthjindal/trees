#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
// bst

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *createnode(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node *searchnode(node *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }
    if (root->data < data)
    {
        return searchnode(root->right, data);
    }
    else
    {
        return searchnode(root->left, data);
    }
}

node *insert(node *temp, int data)
{
    if (temp == NULL)
    {
        return createnode(data);
    }
    else if (data < temp->data)
    {
        temp->left = insert(temp->left, data);
    }
    else if (data > temp->data)
    {
        temp->right = insert(temp->right, data);
    }
    return temp;
}


int finddepth(node *root, int count, int data)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == data)
    {
        return count;
    } 
    if (root->data < data)
    {
        return finddepth(root->right, count + 1, data);
    }
    else
    {
        return finddepth(root->left, count + 1, data);
    }
}
//function to check whether a givne tree is a binary tree or not
bool checkbt(node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left != NULL && root->data < root->left->data)
    {
        return false;
    }
    else if (root->right != NULL && root->data > root->right->data)
    {
        return false;
    }
    if (checkbt(root->left) == 0 || checkbt(root->right) == 0)
    {
        return false;
    }
    return true;
}

void inorder(node *temp)
{
    
    if (temp != NULL)
    {
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}

bool check(node *root,int target_Sum)
{
    if(root==NULL)
    {
        return false;
    }
    //condition applied whenever we have reached the root node
    if(root->left==NULL&&root->right==NULL)
    {
        return root->data==target_Sum;
    }
    bool left=check(root->left,target_Sum-root->data);
    bool right=check(root->right,target_Sum-root->data);
    return left||right;
}


struct node* lca(struct node* root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
 
    // If both n1 and n2 are smaller than root, then LCA
    // lies in left
    if (root->data > n1 && root->data > n2)
        return lca(root->left, n1, n2);
 
    // If both n1 and n2 are greater than root, then LCA
    // lies in right
    if (root->data < n1 && root->data < n2)
        return lca(root->right, n1, n2);
 
    return root;
}

void findksmall(node *root,int k,int* count)
{
    if(root==NULL)
    {
        return ;
    }
    //since traversing in inordr is a sorted thing 
    findksmall(root->left,k,count);
    (*count)++;
    if(*count==k)
    {
        printf("%d",root->data);
        return;
    }
    findksmall(root->right,k,count);
    return;  
}
//get the stored stored in an array in a sorted way
void getinorder(node *temp,int** arr,int* count)
{
    
    if (temp != NULL)
    {/* code */
        getinorder(temp->left,arr,count);
        (*arr)[(*count)++]=temp->data;

       
        getinorder(temp->right,arr,count);
    }
 
}

node *delete(node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (val < root->data)
    {
        root->left = delete(root->left, val);
        return root;
    }
    else if (val > root->data)
    {
        root->right = delete (root->right, val);
        return root;
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL && root->left != NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            //inorder successor
            node *temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = delete (root->right, temp->data);
            return root;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        root = insert(root, arr[i]);
    }
    // inorder(root);
    // printf("\n");
    // root = delete(root,arr[4]);
    // inorder(root);
    // int count = 0;
    // count = finddepth(root, count, 50);
    // printf("\n%d\n", count);
    int *arr1 = (int *)malloc(sizeof(int) * 1000);
    // printf("%d\n",root->data);
    int var=0;
    // getinorder(root,&ar1,&var);r
    // for (int i = 0; i < var; i++)
    // {
    //     printf("%d \n", arr1[i]);
        
    // }
    // if(check(root,50))
    // {
    //     printf("yes");
    // }
    // else
    // {
    //     printf("no");
    // }
    int count = 0;
    findksmall(root,3,&count);
    
    //    root=createnode(20);
//    root->left=createnode(70);
//     if (checkbt(root))
//     {
//         printf("true");
//     }
//     else
//     {
//         printf("false");
//     }
    return 0;
}