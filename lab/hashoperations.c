#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node
{
    struct node* next;
    int data;
}node;


node * createnode(int data)
{
    node* n = (node*)malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}
typedef node* list;

typedef struct hash
{
    list* arr;
    int size;
}hash;

typedef hash* hashtable;

hashtable create(int size)
{
    hashtable h = (hashtable)malloc(sizeof(hash));
    h->size = size;
    h->arr = (list*)malloc(sizeof(list)*size);
    for(int i=0;i<size;i++)
    {
        h->arr[i] = NULL;
    }
    return h;
}
int gethash(hashtable h,int d)
{
    
    return (d%100000);
}
void insert(hashtable h,int data)
{
    int index=gethash(h,data);
    if(h->arr[index]==NULL)
    {
        h->arr[index]=createnode(data);
    }
    // else
    // {
    //     node* temp=h->arr[index];
    //     while(temp->next!=NULL)
    //     {
    //         temp=temp->next;
    //     }
    //     temp->next=createnode(data);
    // }
}

void delete(hashtable h,int data)
{
    int index=gethash(h,data);
    if(h->arr[index]==NULL)
    {
        return ;
    }
    else
    {
        node* temp=h->arr[index];
        h->arr[index]=NULL;
    }

   
}

int find(hashtable h,int data)
{
    int index=gethash(h,data);
    if(h->arr[index]==NULL)
    {
        return 0;
    }
    else
    {

        node* temp=h->arr[index];
        while(temp!=NULL)
        {
            if(temp->data==data)
            {
                return 1;
            }
            temp=temp->next;
        }
        
    }
    return 0;
}
void printtable(hashtable h)
{
    for(int i=0;i<h->size;i++)
    {
        node* temp=h->arr[i];
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    hashtable h=create(100000);
    for (int  i = 0; i <n; i++)
    {
        char sa[7];
        scanf("%s",sa);
        if(strcmp(sa,"INSERT")==0)
        {
            int data;
            scanf("%d",&data);
            insert(h,data);

        }
        if(strcmp(sa,"DELETE")==0)
        {
            int data;
            scanf("%d",&data);
            delete(h,data);
        }
        if(strcmp(sa,"SEARCH")==0)
        {
            int a;
            scanf("%d",&a);
            if(find(h,a)==1)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        } 
        // printtable(h);     
    }
    
}