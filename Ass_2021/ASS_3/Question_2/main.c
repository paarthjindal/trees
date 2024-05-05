#include<stdio.h>
#include<stdlib.h>
#include"tree_node.h"
#include<string.h>
nodeptr create_bst(int start , int end, int *arr){
    if(start>end){
        return NULL;
    }
    if(start == end){
        nodeptr temp  =InitTree();
        temp->element = arr[start];
        return temp;
    }
    int mid = (start+end)/2;
    nodeptr temp  =InitTree();
    temp->element = arr[mid];

    temp->left = create_bst(start , mid-1 , arr);
    if(temp->left!=NULL)
        temp->left->up = temp;
    temp->right = create_bst(mid+1 , end , arr);
    if(temp->right!=NULL)
        temp->right->up = temp;
    return temp;
}

void find_finall(nodeptr root , char*s){
   
    for(int i=0; s[i]!='\0' ; i++){
        if(s[i] == 'U'){
            if(root->up!=NULL){
                root=root->up;
            }
        }
        else if(s[i] == 'L'){
            if(root->left!=NULL){
                root=root->left;
            }
        }
        else if(s[i]=='R'){
            if(root->right != NULL){
                root=root->right;
            }
        }
    }  
    printf("%d\n", root->element); 
}

int main(){
    int n,t;
    scanf("%d %d", &n , &t);
    int arr[n];
    for(int i=0;i<n; i++){
        arr[i] = i+1;
    }
    //n->always odd.
    nodeptr head = create_bst( 0 , n-1, arr);
    InorderTraversal(head);
    while(t--){
        int ele;
        scanf("%d" , &ele);
        char s[100005];
        scanf("%s",s);
        nodeptr root = Find(ele , head );

        find_finall(root , s);
    }
}