#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
typedef struct adjlist{
    struct node* head;
}adjlist;
typedef struct graph{
    int vertices;
    struct adjlist* array;
}graph;
node* createnode(int value) {
    node* nnode=(node*)malloc(sizeof(node));
    nnode->data=value;
    nnode->next=NULL;
    return nnode;
}
graph* creategraph(int nums) {
   graph* ansgraph=(graph*)malloc(sizeof(ansgraph));
   ansgraph->vertices=nums;
   ansgraph->array=(adjlist*)malloc(sizeof(adjlist)*(nums));
   for(int i=0;i<nums;i++) {
    ansgraph->array[i].head=NULL;
   }
    return ansgraph;
}
// add edge from s to d
void addedge(graph* g,int s,int d) {
        node* nnode=createnode(d);
        nnode->next=g->array[s].head;
        g->array[s].head=nnode;
}
void printgraph(graph* g) {
    for(int i=0;i<g->vertices;i++) {
        node* temp=g->array[i].head;
        while(temp!=NULL) {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main() {
    int n;
    scanf("%d",&n);
    graph* ansgraph=creategraph(n);
    for(int i=0;i<n;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        addedge(ansgraph,a,b);
    }
    printgraph(ansgraph);
    return 0;
}