#include<stdio.h>
#include<stdlib.h>
#include "./hash.h"
const int p=10007;
ht create_ht(int n)
{
    ht h=(ht)malloc(sizeof(HashTable));
    h->buckets=(List*)malloc(sizeof(List)*p);
    for(int i=0;i<p;i++)
    {
        h->buckets[i]=NULL;
    }
    return h;
}
long int getHash(char* str)
{
    long int hash=0;
    int t;
    for(int i=0;i<10;i++)
    {
        if(str[i]=='\0')
        {
            break;
        }
        t=str[i]-'a'+1;
        hash=(hash+t*t*t)%p;
    }
    return hash;
}
//Using seperate chaining to create clusters
void insert(ht h,char* str)
{
    long int k=getHash(str);
    List t=h->buckets[k];
    List NewNode=(List)malloc(sizeof(ListNode));
    NewNode->str=str;
    NewNode->next=NULL;
    if(t==NULL)
    {
       h->buckets[k]=NewNode;
       return;
    }
    while(t->next!=NULL)
    {
        t=t->next;
    }
    t->next=NewNode;
    return;
}
//Check and print
int ifanagrams(char* a,char* b)
{
    int freq1[26],freq2[26];
    for(int i=0;i<26;i++)
    {
        freq1[i]=0;
        freq2[i]=0;
    }
    for(int i=0;i<10;i++)
    {
        if(a[i]=='\0' || b[i]=='\0')
        {
            break;
        }
        freq1[a[i]-'a']++;
        freq2[b[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(freq1[i]!=freq2[i])
          return 0;
    }
    return 1;

}
void find_and_print(ht h,char* q)
{
    long int k=getHash(q);
    if(h->buckets[k]==NULL)
    {
        printf("-1\n");
        return;
    }
    List t=h->buckets[k];
    int count=0;
    while(t!=NULL)
    {
       if(ifanagrams(q,t->str))
       {
          count++;
          printf("%s ",t->str);
       }
        t=t->next;
    }
    if(count==0)
    {
        printf("-1");
    }
    printf("\n");
}
