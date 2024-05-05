#include<stdio.h>
#include<stdlib.h>
#include "./hash.h"
int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    char* A1[n];
    ht h=create_ht(n);
    for(int i=0;i<n;i++)
    {
        A1[i]=(char*)malloc(sizeof(char)*11);
        scanf("%s",A1[i]);
        insert(h,A1[i]);
    }
    char* query=(char*)malloc(sizeof(char)*11);
    for(int i=0;i<q;i++)
    {
        scanf("%s",query);
        find_and_print(h,query);
    }
    free(query);
    return 0;
}