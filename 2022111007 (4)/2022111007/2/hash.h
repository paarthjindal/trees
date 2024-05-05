#ifndef __HASH_H__
#define __HASH_H__
typedef struct HashTable
{
    int *buckets;
} HashTable;
typedef HashTable *ht;
ht create_ht(int n);
int getHash(int start,int end);
void insert(ht h,int maxl,int start,int end);
void delete_ht(ht h);
int index_pal(char* str,int len,int key);
int isPalindrome(ht h,char* str,int n,int start,int end);
#endif