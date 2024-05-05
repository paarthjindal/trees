#ifndef __HASH_H_
#define __HASH_H_
typedef struct ListNode
{
    char* str;
    struct ListNode* next;
} ListNode;
typedef ListNode* List;
typedef struct HashTable
{
  List* buckets;
} HashTable;
typedef HashTable* ht;
ht create_ht(int n);
long int getHash(char* str);
void insert(ht h,char* str);
int ifanagrams(char* a,char* b);
void find_and_print(ht h,char* q);
#endif