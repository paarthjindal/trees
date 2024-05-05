#include <stdio.h>
#include <stdlib.h>
#include "./hash.h"

ht create_ht(int n)
{
    ht h = (ht)malloc(sizeof(HashTable));
    h->buckets = (int *)malloc(sizeof(int) * (2*n-1));
    for (int i = 0; i < 2*n-1; i++)
    {
        h->buckets[i]=-1;
    }
    return h;
}
int getHash(int start,int end)
{
    return (end+start);
}
void insert(ht h,int maxl,int start,int end)
{
    int hash=getHash(start,end);
    h->buckets[hash]=maxl;
}
void delete_ht(ht h)
{
    free(h->buckets);   
    free(h);
}
int index_pal(char* str,int len,int key)
{
    int j,k;
    int maxl;
    if(key%2==0)
    {
        maxl=1;
        j=key-2;
        k=key+2;
    }
    else
    {
        maxl=0;
        j=key-1;
        k=key+1;
    }
    for(;j>=0 && k<2*len-1;k+=2,j-=2)
    {
        if(str[j/2]!=str[k/2])
        {
            break;
        }
        maxl+=2;
    }
    return maxl;
}
int isPalindrome(ht h,char* str,int n,int start,int end)
{
    int key=getHash(start,end);
    int len=end-start+1;
    if(h->buckets[key]==-1)
    {
        insert(h,index_pal(str,n,key),start,end);
    }
    if(h->buckets[key]>=len)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
