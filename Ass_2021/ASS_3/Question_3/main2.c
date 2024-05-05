
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Item node;
typedef struct Item* nodeptr;
typedef struct Bucket Bucket;
typedef struct HashTable* Hash_ptr;
struct Item{
    int key;
    int frequency;
    nodeptr next;
};

int count1=0;
int count2=0;

struct Bucket{
    nodeptr items;
};

struct HashTable{
    int a,b,countBucket;
    Bucket* buckets;
};

Hash_ptr init_hash_table(int a, int b, int countBucket);
Hash_ptr insert(Hash_ptr t , int key);
int search(Hash_ptr t , int key);
Hash_ptr Delete(Hash_ptr t, int key);
void print_table(Hash_ptr t); 


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
    
        return t;
    }
    while(temp->next!=NULL){
        count1+=1;
        if(temp->key == key){
            temp->frequency+=1;
            return t;
        }
        temp=temp->next;
    }
    if(temp->key == key){
        temp->frequency+=1;
   
        return t;
    }
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
        count2+=1;
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

    if(temp==NULL){
        return t;
    }
    if(temp->key == key){
   
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
//long long int count= 0;
int main(){
    Hash_ptr t = init_hash_table(1,0,5);
    printf("Table made\n");
    //printf("%d ", t->countBucket);
 
    FILE* ptr = fopen("in10.txt" , "r");
    char str[20];
    int i=1;
    int count_insert = 0;
    int count_search=0;
    while( fscanf(ptr , "%s" , str)!=EOF){
        //printf("Read string\n");
    
        int x;
        fscanf(ptr , "%d" , &x);
        printf("%d\n", i);
        if(strcmp(str , "INSERT")== 0){
            count_insert+=1;
            insert(t,x);
        }
        else if(strcmp(str , "DELETE")== 0){
           
            Delete(t,x);
        }
        else if(strcmp(str , "SEARCH")== 0){
            count_search+=1;
            search(t,x);
        }
        i+=1;
    }
    //printf("out of loop%d\n", i);
    double a = count1/count_insert;
    double b = count2/count_search;
    printf("%f %f \n", a,b);
    free(ptr);

}