#include"tree.h"
#include<stdio.h>
#include<stdlib.h>
#include "queue1.h"


int min(int a , int b){
    if(a<=b){
        return a;
    }
    else{
        return b;
    }
}
int check_increasing(nodeptr head)
{
    if(head->right!=NULL){
        if(head->right->increasing == 2 || head->right->increasing == -1){
            return -1;
        }
        if(head->element >= head->right->minn){
            return -1;
        }
    }   
    if(head->left!=NULL){
        if(head->left->increasing == 2 || head->left->increasing == -1){
            return -1;
        }
        if(head->element <= head->left->maxx){
            return -1;
        }
    }  

    return  1;
}
int check_decreasing(nodeptr head)
{
    if(head->right!=NULL){
        if(head->right->increasing == 2 || head->right->increasing == 1){
            return -1;
        }
        if(head->element <= head->right->maxx){
            return -1;
        }
    }   
    if(head->left!=NULL){
        if(head->left->increasing == 2 || head->left->increasing == 1){
            return -1;
        }
        if(head->element >= head->left->minn){
            return -1;
        }
    }  

    return  1;
}


nodeptr helper(nodeptr head , int* x){

    if(head==NULL){
        return NULL;
    }
    if(head->right==NULL  &&  head->left==NULL) {
        head->maxx = head->element;
        head->minn = head->element;
        head->sum = head->element;
        head->increasing = 0;
        *x = min(*x , head->sum);
        return head;
    }

    // if not leaf node.
    head->right=helper(head->right , x);
    head->left =helper(head->left , x);

    int b1 = check_increasing(head);
    int b2 = check_decreasing(head);

    if(b1==1){
        //printf("vwgdf\n");
        head->sum = head->element;
        head->minn=head->element;
        head->maxx=head->element;
        head->increasing = 1; 
        if(head->right!=NULL){
            head->sum += head->right->sum;
            head->maxx=head->right->maxx;
        }
        if(head->left!=NULL){
            head->sum +=head->left->sum;
            head->minn = head->left->minn;
        }
        
        *x = min(*x , head->sum);
    }
    else if(b2==1){
        head->sum = head->element;
        head->minn=head->element;
        head->maxx=head->element;
        head->increasing = -1;
        if(head->right!=NULL){
            head->sum += head->right->sum;
            head->minn = head->right->minn;
        }
        if(head->left!=NULL){
            head->sum +=head->left->sum;
            head->maxx = head->left->maxx;
        }
        *x = min(*x , head->sum);
    }
    else{
        head->increasing = 2;
    }
    return head;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);

        int arr[n];
        Queueptr qu = CreateQueue(n);
        for(int i=0;i<n ; i++){
            scanf("%d" , &arr[i]);
        }

        nodeptr temp = InitTree();
        temp->element = arr[0];
        Enqueue(qu,temp);
        nodeptr head = temp;
        int left = 1;
       
        for(int i=1; i<n; i++){
            nodeptr top = Top(qu);
            if(top==NULL){
                Dequeue(qu);
                i--;
                continue;
            }
            if(left==1){
                if(arr[i] == 0){
                    top->left==NULL;
                    Enqueue(qu , NULL);
                }
                else{
                    nodeptr tt = InitTree();
                    tt->element = arr[i];
                    top->left=tt;
                    Enqueue(qu , tt);
                }
                left = 0;
            }
            else{
                if(arr[i] == 0){
                    top->right==NULL;
                    Enqueue(qu , NULL);
                }
                else{
                    nodeptr tt = InitTree();
                    tt->element = arr[i];
                    top->right=tt;
                    Enqueue(qu , tt);
                }
                Dequeue(qu);
                left=1;

            }
        }

        InorderTraversal(head);
        printf("\n");


        // we built the tree

        int minimum  = 10000009;
        helper(head , &minimum);        
        printf("%d\n", minimum);
        Delete_tree(temp);
    }
}