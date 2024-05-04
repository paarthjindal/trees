#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    int temp_phone;
    int perm_phone;
    int min_phone;
} node;

typedef struct queue
{
    node **arr;
    int length;
    int front;
    int rear;
} queue;

queue *createqueue(int capacity)
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->arr = (node **)malloc(capacity * sizeof(node *));
    q->length = 0;
    q->front = -1;
    q->rear = -1;
    return q;
}

void push(node *n, queue *q)
{
    if (q->rear == -1)
    {
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = n;
    q->length++;
}

void pop(queue *q)
{
    if (q->length == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    q->front++;
    q->length--;
}

node *newNode(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->temp_phone = 0;
    temp->perm_phone = 0;
    temp->min_phone = 0;
    return temp;
}

node *insertValue(node *root, int *arr)
{
    int c = 0;
    queue *q = createqueue(10000);
    root = newNode(arr[c]);
    c++;
    push(root, q);
    while (q->length != 0)
    {
        node *temp = q->arr[q->front];
        pop(q);
        if (arr[c] == 1)
        {
            temp->left = newNode(arr[c]);

            push(temp->left, q);
        }
        c++;
        if (arr[c] == 1)
        {
            temp->right = newNode(arr[c]);

            push(temp->right, q);
        }
        c++;
    }
    return root;
}

void printlevelorder(node *root)
{
    if (root == NULL)
        return;

    queue *q = createqueue(100);
    push(root, q);
    push(NULL, q);

    while (q->length != 0)
    {
        node *t2 = q->arr[q->front];
        pop(q);
        if (t2 == NULL)
        {
            printf("\n");
            if (q->length != 0)
            {
                push(NULL, q);
            }
        }
        else
        {
            printf("%d ", t2->data);
            if (t2->left != NULL)
                push(t2->left, q);
            if (t2->right != NULL)
                push(t2->right, q);
        }
    }

    free(q->arr);
    free(q);
}
void preorder(node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
int minPhones(node *root)
{
    
    if(root == NULL)
    {
        return 0;
    }
    minPhones(root->left);
    minPhones(root->right);
    root->temp_phone=1;
    if(root->left->temp_phone!=0||root->right->temp_phone!=0)
    {
        if()
    }
}
node* insert(node* val,int value)
{
    if(val==NU)
}
// bool isDescendantEligible(node *n, node *other)
// {
//     if (n == NULL)
//     {
//         return true;
//     }

//     if (other != NULL && (other->data == 1 || n->data == 0))
//     {
//         return false;
//     }

//     return isDescendantEligible(n->left, other) && isDescendantEligible(n->right, other);
// }
// // }
// int minPhones(node *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }

//     // Assign temporary phones to all leaf nodes
//     if (root->left == NULL && root->right == NULL)
//     {
//         root->temp_phone = 1;
//         return 1;
//     }

//     int tempPhones = minPhones(root->left) + minPhones(root->right);

//     // If both left and right children are eligible for permanent phones
//     if (root->left != NULL && root->right != NULL)
//     {
//         if (isDescendantEligible(root->left, root->right->left) &&
//             isDescendantEligible(root->left, root->right->right) &&
//             isDescendantEligible(root->right, root->left->left) &&
//             isDescendantEligible(root->right, root->left->right))
//         {
//             tempPhones -= 2;
//             root->perm_phone = 1;
//         }
//     }

//     // If left child is eligible for permanent phone
//     else if (root->left != NULL)
//     {
//         if (isDescendantEligible(root->left, root->right))
//         {
//             tempPhones--;
//             root->perm_phone = 1;
//         }
//     }

//     // If right child is eligible for permanent phone
//     else if (root->right != NULL)
//     {
//         if (isDescendantEligible(root->right, root->left))
//         {
//             tempPhones--;
//             root->perm_phone = 1;
//         }
//     }

//     root->temp_phone = tempPhones;
//     return tempPhones;
// }

// Function to check if a node is eligible for a permanent phone without affecting the eligibility of any of its descendant nodes


int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    node *root = NULL;
    queue *q = createqueue(100);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    root = insertValue(root, arr);
    // printf("%d", root->data);
    // printf("%d", root->left->data);
    // printf("%d", root->left->left->left->right->data);

    // printlevelorder(root);

    int ans = minPhones(root);
    printf("%d", ans);
    return 0;
}
