#include"tree_node.h"
#include<stdio.h>
#include<stdlib.h>


nodeptr InitTree(){
    nodeptr head = (nodeptr)malloc(sizeof(node));
    head->right = NULL;
    head->left  = NULL;
    
    return head; 
}

nodeptr go_to_right_leftmost_node(nodeptr root){
    nodeptr temp = root;

    while(temp->left!=NULL){
        temp= temp->left;
    }
    return temp;
}

nodeptr Delete_node(int x, nodeptr root){
    if(root==NULL)
    {
        return NULL;
    }
    if(root->element > x){
        root->left = Delete_node(x,root->left);
        return root;
    }
    else if(root->element < x){
        root->right = Delete_node(x,root->right);
        return root;
    }
    else{
        if(root->right == NULL && root->left == NULL){

            free(root);
            return NULL;
        }
        else if(root->right == NULL && root->left!=NULL){
            nodeptr temp = root->left;
            free(root);
            return temp;
        }
        else if(root->right !=NULL && root->left == NULL){
            nodeptr temp = root->right;
            free(root);
            return temp;
        }
        else{
            nodeptr to_delete = go_to_right_leftmost_node(root->right);
            root->element = to_delete->element;
            root->right = Delete_node(to_delete->element , root->right);
            return root;
        }
    }
}

nodeptr Find(int x , nodeptr root){
    if(x > root->element){
        return Find(x, root->right);
    }
    else if(x < root->element){
        return Find(x , root->left);
    }
    else{
        return root;
    }
}

nodeptr Insert( int x , nodeptr head ){
    if(head == NULL){
        head = InitTree();
        head->element = x;
        return head;
    }
    else{
        if(x > head->element){
            head->right = Insert(x,head->right);
        }
        else{
            head->left = Insert(x,head->left );
        }
        return head;
    }
}



void InorderTraversal(nodeptr root){
    if(root==NULL)
    {
        return ;
    }
    InorderTraversal(root->left);
    printf("%d ", root->element);
    InorderTraversal(root->right );
}

//preorder -> root , left , right
//postorder-> left . right , root

void PreOrder(nodeptr root){
    if(root==NULL){
        return ;
    }
    printf("%d ", root->element);
    PreOrder(root->left);
    PreOrder(root->right);
    return;
}

void PostOrder(nodeptr root){
    if(root == NULL){
        return ;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->element);
    return ;
}


// void Inorder_Itretive(nodeptr root){
//     stackptr st = Intial_Stack(100);
//     push(st , root->element);
//     nodeptr curr = root->left;

//     while( IsEmpty(st) == 0){
//         if(curr!=NULL){
//             push(st,curr->element);
//             curr=curr->left;
//         }
//         else{
//             curr = Top(st);
//             printf("%d ", curr->element);

//             if(curr->right->left == NULL && curr->right->right ==NULL){
//                 printf("%d ", curr->right->element);
//                 pop(st);
//             }
//             else if(curr->right->left!=NULL){
//                 push(st, curr->right);
//                 curr = curr->right->left;
//             }
//             else{
                
//             }
//         }
//     }
// }