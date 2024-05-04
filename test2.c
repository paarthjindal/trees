#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* constructTree(int* levelOrder, int n) {
    if (n <= 0)
        return NULL;

    struct TreeNode* root = createNode(levelOrder[0]);
    struct TreeNode* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;

    while (front < rear && i < n) {
        struct TreeNode* current = queue[front++];
        int leftVal = (i < n) ? levelOrder[i++] : 0;
        int rightVal = (i < n) ? levelOrder[i++] : 0;

        if (leftVal != 0) {
            current->left = createNode(leftVal);
            queue[rear++] = current->left;
        }

        if (rightVal != 0) {
            current->right = createNode(rightVal);
            queue[rear++] = current->right;
        }
    }
    return root;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}
int max(int a, int b) {
    return (a > b) ? a : b;
}

int* minPhones(struct TreeNode* root) {
    int* result = (int*)malloc(2 * sizeof(int));

    if (root == NULL) {
        result[0] = 0;
        result[1] = 0;
        return result;
    }

    int* leftResult = minPhones(root->left);
    int* rightResult = minPhones(root->right);

    result[0] = max(1, leftResult[1] + rightResult[1] - root->val);
    result[1] = leftResult[0] + rightResult[0] + root->val - result[0];

    free(leftResult);
    free(rightResult);

    return result;
}

int minPhonesDistribution(int* levelOrder, int n) {
    struct TreeNode* root = constructTree(levelOrder, n);
    int* result = minPhones(root);
    int phonesRequired = result[0];
    free(result);
    return phonesRequired;
}

int main() {
    int levelOrder[] = {1, 1,1,1,1,0,1,0,1,1,0,1,0,0,0,0,0,0,1};
    int n = sizeof(levelOrder) / sizeof(levelOrder[0]);
    printf("Minimum number of phones required: %d\n", minPhonesDistribution(levelOrder, n));
    return 0;
}
