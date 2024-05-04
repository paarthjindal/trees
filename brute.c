#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef struct stnode{
    long long int data;
    int count;
    int index;
    struct stnode* next;
}stnode;
typedef stnode* Node;
typedef struct sthash{
    Node* node;
}sthash;
typedef sthash* Hash;
Node createnode(int data,int count,int index)
{
    Node n=(Node)malloc(sizeof(stnode));
    n->count=count;
    n->data=data;
    n->next=NULL;
    n->index=index;
    return n;
}
// Node emptynode()
// {
//     Node n=(Node)malloc(sizeof(stnode));
//     n->next=NULL;
//     return n;
// }
Hash createhash()
{
    int n=1e5;
    Hash h=(Hash)malloc(sizeof(sthash));
    h->node=(Node*)malloc(sizeof(Node)*(n+1));
    // for(int x=0;x<1e7;x++)
    // {
    //     h->node[x]=emptynode();
    // }
    return h;
}
int gethash(long long int a)
{
    return a%100000;
}
void inserthash(long long int data,Hash* h,int index)
{
    int n=gethash(data);
    int m=gethash(data-1);
    Node temp=(*h)->node[m];
    while(temp!=NULL && temp->data!=(data-1))
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        Node new=createnode(data,1,index);
        (*h)->node[n]=new;
        return;
    }
    else
    {
        long long int count=temp->count;
        temp=(*h)->node[n];
        Node new=createnode(data,count+1,index);
        new->next=temp;
        (*h)->node[n]=new;
        return;
    }
}
void countmax(Hash* h,int size,int *arr)
{
    int count=0;
    int num=0;
    for(int x=0;x<1e5+1;x++)
    {
        Node temp=(*h)->node[x];
        if(temp==NULL)
        {
            continue;
        }
        else
        {
            while(temp!=NULL)
            {
                if(temp->count>count)
                {
                    count=temp->count;
                    num=temp->data;
                }
                temp=temp->next;
            }
        }
    }
    // int arr[count+1];
    // int str=num-count;
    // int g=gethash(num);
    // int gs=gethash(str);
    
    // for(int x=g;x>=gs;x--)
    // {
    //     Node temp=(*h)->node[x];
    //     while(temp!=NULL)
    //     {
    //         if(temp->data==num)
    //         {
    //             arr[num-str]=temp->index;
    //             num--;
    //         }
    //         temp=temp->next;
    //         if(num==str)
    //         {
    //             break;
    //         }
    //     }
    // }
    printf("%d\n",count);
    int start=num-count+1;
    for(int x=0;x<size;x++)
    {
        if(arr[x]==start)
        {
            printf("%d ",x);
            start++;
        }
    }
    // for(int x=1;x<=count;x++)
    // {
    //     printf("%d ",arr[x]);
    // }
}
int main()
{
    int a;
    scanf("%d",&a);
    Hash table=createhash();
    // Node t=table->node[0];
    // if(t==NULL)
    // {
    //     printf("NULL");
    // }
    int arr[a];
    for(int x=0;x<a;x++)
    {
        // printf("ji");
        long long int b;
        scanf("%lld",&b);
        arr[x]=b;
        inserthash(b,&table,x);
        // printf(" %d %d\n",table->node[0]->data,table->node[0]->count);
        // printf("jo");
    }
    // printf("haa");
    countmax(&table,a,arr);
    // printf("%d\n",n);
    return 0;
}