#ifndef TREE_NODE_H
#define TREE_NODE_H

typedef struct node node;
typedef struct node* nodeptr;

struct node{
    int element;
    nodeptr right;
    nodeptr left;
    int maxx;
    int minn;
    int sum;
    int increasing;
    //1 for increasing ,
    // -1 for decreasing ,
    // 0 for leaf node , 
    //2 for nothing.
};

nodeptr Insert( int x , nodeptr head );
nodeptr InitTree();
void InorderTraversal(nodeptr root);
void PreOrder(nodeptr root);
void PostOrder(nodeptr root);
nodeptr Find(int x , nodeptr head);
nodeptr Delete_node(int x, nodeptr root);
nodeptr go_to_right_leftmost_node(nodeptr root);
void Delete_tree(nodeptr root);
#endif