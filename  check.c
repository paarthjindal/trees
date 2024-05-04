#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new binary tree node.
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find the subtree with the lowest sum of all its nodes.
struct TreeNode* findLowestSumSubtree(struct TreeNode* root, int* minSum) {
    if (root == NULL)
        return NULL;

    // Recursive calls to left and right subtrees
    struct TreeNode* leftSubtree = findLowestSumSubtree(root->left, minSum);
    struct TreeNode* rightSubtree = findLowestSumSubtree(root->right, minSum);

    // Calculate the sum of the current subtree
    int sum = root->val;
    if (leftSubtree != NULL)
        sum += leftSubtree->val;
    if (rightSubtree != NULL)
        sum += rightSubtree->val;

    // Check if the sum is the lowest encountered so far
    if (sum < *minSum) {
        *minSum = sum;
        return root; // Update the subtree root with lowest sum
    }

    return (sum == *minSum) ? root : ((sum < 0) ? leftSubtree : rightSubtree);
}

// Function to print the inorder traversal of a binary tree (ascending or descending).
void printInorder(struct TreeNode* root, int ascending) {
    if (root == NULL)
        return;

    if (ascending) {
        printInorder(root->left, ascending);
        printf("%d ", root->val);
        printInorder(root->right, ascending);
    } else {
        printInorder(root->right, ascending);
        printf("%d ", root->val);
        printInorder(root->left, ascending);
    }
}

int main() {
    // Example binary tree
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int minSum = INT_MAX;
    struct TreeNode* lowestSumSubtree = findLowestSumSubtree(root, &minSum);

    printf("Subtree with lowest sum: ");
    printInorder(lowestSumSubtree, lowestSumSubtree->val >= 0);
    printf("\n");

    return 0;
}
