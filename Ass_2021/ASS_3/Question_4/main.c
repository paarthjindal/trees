#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
typedef long long int ll;
typedef struct node node;
typedef struct node* nodeptr;
typedef ll ElementType;

struct node{
    // ElementType element;
    nodeptr right;
    nodeptr left;
    char ch;
    ll idx_preorder; 
};

nodeptr InitTree(){
    nodeptr head = (nodeptr)malloc(sizeof(node));
    head->right = NULL;
    head->left  = NULL;
    
    return head; 
}
long long int idx = 1;
void preorder_update_karo(nodeptr root , char* pre_order_string){
    if(root==NULL){
        return ;
    }
    pre_order_string[idx] = root->ch;
    root->idx_preorder = idx;
    idx+=1;
    preorder_update_karo(root->left , pre_order_string);

    preorder_update_karo(root->right , pre_order_string);
    return;
}
void print_inorder(nodeptr root){
    if(root==NULL)return;
    //printf("I am here\n");
    print_inorder(root->left);
    printf("%c->%lld ",root->ch, root->idx_preorder);
    print_inorder(root->right);
}
int main(){
    ll n;
    scanf("%lld" , &n);
    nodeptr arr[n+1];
    char string[n+1];
    scanf("%s" , string);
    for(ll i=0;string[i]!='\0'; i++){
        nodeptr x = InitTree();
        // x->element = i+1;
        x->ch = string[i];
        arr[i+1] = x;
    }    

    for(ll i=0;i<n-1; i++){
        ll a,b,c;
        scanf("%lld %lld %lld", &a,&b,&c);
        if(c==1){
            arr[a]->left = arr[b];
        }
        else if(c==2){
            arr[a]->right = arr[b];
        }
        //printf("Done with %lld input\n", i+1);
    }
    //print_inorder(arr[1]);

    char str[1000007];
    scanf("%s", &str[1]);

    char pre_order_string[1000007];
  
    preorder_update_karo(arr[1] , pre_order_string);
    //print_inorder(arr[1]);
    //printf("%s" , &pre_order_string[1]);
    ll t;
    scanf("%lld" , &t);
    //t+=1;
    while(t--){
        //printf("In loop\n");
        int a;
        scanf("%d", &a);
        //printf("Taken the input\n");
        if(a==1){
            ll b;
            char ch1;
            scanf("%lld %c", &b, &ch1);
            
            arr[b]->ch = ch1;
            pre_order_string[arr[b]->idx_preorder] =ch1;
            //printf("%s\n" , &pre_order_string[1]);
            //print_inorder(arr[1]);
            //printf("\n");
        }
        else if(a==2){
            ll l,r,i;
            scanf("%lld %lld %lld", &l,&r,&i);

            //substring(l,r)        arr[i] is the node for preorder
            if(strncmp(&str[l] , &pre_order_string[arr[i]->idx_preorder]  , (r-l+1)) == 0){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
    }
}