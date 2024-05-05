#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

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


typedef struct Queue Queue;
typedef struct Queue* Queueptr; 

struct Queue{
    int size;
    int front,rear;
    nodeptr* arr;
    int num_elements;
};

Queueptr CreateQueue(int s);
void Enqueue(Queueptr q , nodeptr x);
void Dequeue(Queueptr q);
nodeptr Top(Queueptr q);
int IsEmpty(Queueptr q);
int IsFull(Queueptr q);

void printQueue(Queueptr Q);
void clearQueue(Queueptr Q);
void deleteQueue(Queueptr Q);
void printQueue(Queueptr Q);




nodeptr InitTree(){
    nodeptr head = (nodeptr)malloc(sizeof(node));
    head->right = NULL;
    head->left  = NULL;
    head->maxx = head->element;
    head->minn = head->element;
    head->sum = 0;
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

Queueptr CreateQueue(int s){
    assert(s>0);
    Queueptr qu = (Queueptr)malloc(sizeof(Queue));
    assert(qu!=NULL);
    qu->size = s;
    qu->front = 0;
    qu->rear = -1;

    qu->arr = (nodeptr*)malloc((s+1)*sizeof(nodeptr));
    assert(qu->arr!=NULL);
    qu->num_elements = 0;
    return qu;
}

void Enqueue(Queueptr q, nodeptr x)
{
    if(!IsFull(q)){
        q->rear = (q->rear+1)%(q->size);
        q->arr[q->rear] = x;
        q->num_elements+= 1;

        return ;
    }
}

void Dequeue(Queueptr q){
    if(!IsEmpty(q)){
        nodeptr x;
        x = q->arr[q->front];
        q->front = (q->front+1)%(q->size);
        q->num_elements -=1;
    }
}

int IsEmpty(Queueptr q){
    return (q->rear==-1);//returns 1 if empty.
}

int IsFull(Queueptr q){
    return (q->num_elements == q->size); 
}
void clearQueue(Queueptr q){
    q->front = 0;
    q->rear  =-1;
    q->num_elements = 0;
}

void DeleteQueue(Queueptr q){
    free(q->arr);
    free(q);
    return ;
}

void printQueue(Queueptr Q){
    if(Q->rear > Q->front){
        for(int i=Q->front; i<=Q->rear; i++ ){
            printf("%d ", (Q->arr[i]->element));
        }
    }
    else{
        for(int i=Q->front; i<=Q->size-1; i++){
            printf("%d ", Q->arr[i]->element);
        }
        for(int i=0;i<=Q->rear ; i++){
            printf("%d ",(Q->arr[i]->element) );
        }
    }
}
nodeptr Top(Queueptr q){
    return q->arr[q->front];
}




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

        //InorderTraversal(head);
        //printf("\n");


        // we built the tree

        int minimum  = 10000009;
        helper(head , &minimum);        
        printf("%d\n", minimum);
        //Delete_tree(temp);
    }
}