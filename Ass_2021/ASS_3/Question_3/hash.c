#include<stdio.h>
#include<stdlib.h>
#include "hash.h"


Hash_ptr init_hash_table(int a, int b, int countBucket){
    Hash_ptr t = (Hash_ptr)malloc(sizeof(struct HashTable));
    t->a = a;
    t->b = b;
    t->countBucket = countBucket;

    t->buckets =(Bucket*)malloc(countBucket * sizeof(Bucket));

    // nodeptr newNode = (nodeptr)malloc(sizeof(node));
    // newNode->key = 100;
    // newNode->next=NULL;
    // newNode->frequency=1;

    for(int i=0; i<countBucket ; i++){
        t->buckets[i].items =NULL;
    }
    return t;
    
}

Hash_ptr insert(Hash_ptr t , int key){
    int pos = ( ((t->a) * key) + t->b )%(t->countBucket);
    
    nodeptr temp = t->buckets[pos].items;

    if(temp==NULL){
        nodeptr newNode = (nodeptr)malloc(sizeof(node));
        newNode->key = key;
        newNode->next=NULL;
        newNode->frequency=1;
        t->buckets[pos].items = newNode; 
        count+=1;
        return t;
    }
    while(temp->next!=NULL){
        count+=1;
        if(temp->key == key){
            temp->frequency+=1;
            return t;
        }
        temp=temp->next;
    }
    if(temp->key == key){
        temp->frequency+=1;
        count+=1;
        return t;
    }
    count+=1;
    nodeptr newNode = (nodeptr)malloc(sizeof(node));
    newNode->key = key;
    newNode->next=NULL;
    newNode->frequency=1;

    temp->next = newNode;
    return t;
}

int search(Hash_ptr t , int key){
    int pos = ( (t->a* key) + t->b )%(t->countBucket);
    
    nodeptr temp = t->buckets[pos].items;

    while(temp!=NULL){
        count+=1;
        if(temp->key == key){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

Hash_ptr Delete(Hash_ptr t, int key){
    int pos = ( (t->a* key) + t->b )%(t->countBucket);
    
    nodeptr temp = t->buckets[pos].items;

    if(temp->key == key){
        count+=1;
        if(temp->frequency==1){
            t->buckets[pos].items = temp->next;
            free(temp);
        }
        else{
            temp->frequency-=1;
        }

        return t;
    }
    nodeptr prev = t->buckets[pos].items;
    nodeptr curr = prev->next;
    while(curr!=NULL){
        count+=1;
        if(curr->key == key){
            if(curr->frequency==1){
                t->buckets[pos].items = curr->next;
                free(curr);
            }
            else{
                curr->frequency-=1;
            }
            return t;
        }
        prev = curr;
        curr=curr->next;
    }
    return t;
}

void print_table(Hash_ptr t){
    int n = t->countBucket;

    for(int i=0;i<n ; i++){
        nodeptr temp = t->buckets[i].items;
        int count = 0;
        
        while(temp!=NULL){
            printf("<%d %d> ", temp->key , temp->frequency);
            temp=temp->next;
            count+=1;
        }
        if(count!=0)
            printf("\n");
        
        
    }
    printf("-------------\n");
}