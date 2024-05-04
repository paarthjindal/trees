#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
// int findsqrt(int a)
// {
//     if(a==0||a==1) 
//     {
//         return a;
//     }
//     int low=1;
//     int high=a;
//     int ans=0;
//     while(low<=high)
//     {
//         // printf("ehllo");
//         int mid=low+(high-low)/2;
//         if(mid*mid==a)
//         {
//             ans=mid;
//             return ans;
//         }
//         else if(mid*mid<=a&&(mid+1)*(mid+1)>a)
//         {
//            ans=mid;
//            return ans;
//         }
//         else if(mid*mid<a)
//         {
//             low=mid+1;
//         }
//         else if(mid*mid>a)
//         {
//             high=mid-1;
//         }
      
//     }
//     return ans;
// }

// int main() {
//     int n;
//     scanf("%d", &n);
    
//     int res=findsqrt(n);
//     printf("%d\n", res);
//     return 0;
// }
// #include <stdbool.h>
int check(int mid, int n,int k)
{
    
}
int binarysearch(int n,int k)
{
    int low=1;
    int high=n*k;
    int ans=0;
    while(low<high)
    {
        int mid=low+(high-low)/2;
        int res=0;
        res=check(mid,n,k);
        if(res==1)
        {
            low=mid+1;
        }
        else if(res==0)
        {
            high=mid-1;
        }
    }
}
int main()
{
    int k;
    scanf("%d", &k);
    int n;
    scanf("%d", &n);
    int ans=binarysearch(n,k);

    return 0;
}