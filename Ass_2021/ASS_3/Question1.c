#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef long long int ll;

// ll POWER_BATA_BHAI(ll start , ll end, ll ele, ll root , ll pow){
//     if(start >= end){
//         return 0;
//     }
//     ll power ;
//     ll mid = (start+end)/2;
//     if(mid+1 == root){
//         power = pow;
//         if(mid+1 == ele){
//             return power;
//         }
//         else{
//             if(mid+1 > ele){
//                 return find_power(start , mid-1, ele , root, power);
//             }
//             else{
//                 return find_power(mid+1 , end , ele, root , power);
//             }
//         }
//     }
//     else{
//         if(mid+1 == ele){
//             return pow/2;
//         }
//         else if(mid+1 > ele){
//             return find_power(start , mid-1, ele , root, pow/2);
//         }
//         else{
//             return find_power(mid+1 , end , ele, root , pow/2);
//         }
//     }
    
// }

    
// ll POWER_BATA_BHAI(ll n, ll ele, ll start , ll end , ll bhai_ki_power){

//     ll mid =(start+end)/2;

//     if(start==end){
//         return 0;
//     }

//     if(mid==ele){
//         return bhai_ki_power;
//     }
//     else if(mid < ele){
//         POWER_BATA_BHAI(n,ele , mid+1,end , bhai_ki_power/2);
//     }
//     else{
//         POWER_BATA_BHAI(n,ele , start , mid-1,  bhai_ki_power/2);
//     }
// }

// ll POWER_BATA_BHAI(ll s , ll e, ll n, ll curr_ele){
//     ll power = (s+e)/4;
//     while(s<=e){
//         ll mid = (s+e)/2;
//         if(mid>curr_ele){
//             e=mid-1;
//         }
//         else if(mid<curr_ele){
//             s=mid+1;
//         } 
//         else{
//             return power;
//         }
//         power=power/2;
//     }

// }

ll BAAP_KON_HAI_TERA(ll s  , ll e,ll curr_ele,ll n){

    if(((s)+(e))/ 2 == curr_ele){
        return -1;
    }
    ll prev_ele = -1;
    while(s <= e){
        ll mid = (s+e)/2;
        
        if(mid > curr_ele){
            e = mid-1;
        }
        else if(mid < curr_ele){
            s=mid+1;
        }
        else{
            return prev_ele;
        }
        prev_ele = mid;
    }
    return -1;
}

ll find_finall_element(char* str , ll power , ll curr_ele, ll n){
    for(ll i=0;str[i]!='\0';i++){
        if(str[i] == 'L'){
            if(power!=0){
                curr_ele = curr_ele - power;
                power = power/2;
            }
                //printf("%lld " , power);
        }
        else if(str[i] == 'R'){
            if( power!=0 ){
                curr_ele = curr_ele + power;
                power = power/2;
            }
        }
        else{
            ll x = BAAP_KON_HAI_TERA(1,n,curr_ele,n);
    
            if(x!=-1){
                curr_ele=x;
                if(power == 0){
                    power=1;
                }
                else{
                    power=power*2;
                }
            }
                
        }
    }
    return curr_ele;
}

int main(){
    ll n,t;
    scanf("%lld %lld", &n, &t);
   
    // for(ll i=0;i<n; i++){
    //     arr[i] = i+1;
    // }
    while(t--){
        ll ele;
        scanf("%lld", &ele);

        char str[1000000];
        scanf("%s", str);


        ll level =0 , temp  = ele;
        while(temp%2==0){
            ++level;
            temp = temp/2;
        }

        ll power = pow(2,level-1);
        //ll power = POWER_BATA_BHAI(1,n , n,ele);
        ll q = find_finall_element(str , power  , ele , n );
        printf("%lld\n", q);
    }
}