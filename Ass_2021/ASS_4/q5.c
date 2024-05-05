#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;

int cmpfunc (const void * a, const void * b)
{
    if( *(long long int*)a - *(long long int*)b < 0 )
        return -1;
    if( *(long long int*)a - *(long long int*)b > 0 )
        return 1;
    return 0;
}


int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int k;
        scanf("%d", &k);
        ll mat[k][k];
        ll diff_mat[k][k];
        for(int i=0;i<k; i++){
            for(int j=0; j<k; j++){
                scanf("%lld", &mat[i][j]);
            }

            qsort( &mat[i] , k , sizeof(ll) , cmpfunc);
        }

        ll sum_initial = 0 ;
        for(int i=0;i<k; i++){
            sum_initial+=mat[i][0] ;
        }

        for(int i=0;i<k; i++){
            for(int j=0; j<k; j++){
                if(j>=1){
                    diff_mat[i][j] = mat[i][j] - mat[i][j-1];
                }
                else{
                    diff_mat[i][j] = 0;
                }
            }
        }
        // for(int i=0;i<k ;i++){
        //     for(int j=0; j<k ; j++){
        //         printf("%lld ", diff_mat[i][j]);
        //     }
        //     printf("\n");
        // }
        ll diff_array[k];
        int count = 0;

        int pointers[k];
        ll curr_sum[k];
        for(int i=0;i<k; i++){
            pointers[i] = 0;
            curr_sum[i] = 0;
        }

        while(count<k-1){
            printf("***********\n");
            for(int i=0;i<k ;i++){
                for(int j=0; j<k ; j++){
                    printf("%lld ", diff_mat[i][j]);
                }
                printf("\n");
            }
            printf("***********\n");
            ll min_diff = diff_mat[0][pointers[0]+1];
            int min_row_idx = 0;
            for(int i=1;i<k; i++){
                if(   diff_mat[i][pointers[i]+1] < min_diff){
                    min_row_idx = i;
                    min_diff=diff_mat[i][pointers[i]+1];
                }
            }
            //printf("%lld\n",min_diff) ;
            pointers[min_row_idx] +=1;
            diff_mat[min_row_idx][pointers[min_row_idx]+1] += diff_mat[min_row_idx][pointers[min_row_idx]];
            curr_sum[count] = diff_mat[min_row_idx][pointers[min_row_idx]];
            count+=1;
        }
        printf("***********\n");
            for(int i=0;i<k ;i++){
                for(int j=0; j<k ; j++){
                    printf("%lld ", diff_mat[i][j]);
                }
                printf("\n");
            }
            printf("***********\n");
        printf("%lld ", sum_initial);
        for(int i=0;i<count ; i++){
            printf("%lld ", sum_initial + curr_sum[i]);
        }
        printf("\n");
    }
}