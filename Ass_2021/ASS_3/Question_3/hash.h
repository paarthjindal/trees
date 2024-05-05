#ifndef hash_h
#define hash_h
long long int count=0;
typedef struct Item node;
typedef struct Item* nodeptr;
typedef struct Bucket Bucket;
typedef struct HashTable* Hash_ptr;
struct Item{
    int key;
    int frequency;
    nodeptr next;
};

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

#endif