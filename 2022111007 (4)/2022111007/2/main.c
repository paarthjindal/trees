#include<stdio.h>
#include<stdlib.h>
#include "./hash.h"
int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    char str[n + 1];
    scanf("%s", str);
    ht h=create_ht(n);
    int l, r;
    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", &l, &r);
        if (isPalindrome(h,str,n,l - 1, r - 1))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    delete_ht(h);
    return 0;
}