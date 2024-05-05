#ifndef TREE_NODE_H
#define TREE_NODE_H

typedef struct node node;
typedef struct node* nodeptr;
typedef int ElementType;

struct node{
    ElementType element;
    nodeptr right;
    nodeptr left;
    char ch;
};

nodeptr Insert( ElementType x , nodeptr head );
nodeptr InitTree();
void InorderTraversal(nodeptr root);
void PreOrder(nodeptr root);
void PostOrder(nodeptr root);
nodeptr Find(ElementType x , nodeptr head);
nodeptr Delete_node(ElementType x, nodeptr root);
nodeptr go_to_right_leftmost_node(nodeptr root);
#endif