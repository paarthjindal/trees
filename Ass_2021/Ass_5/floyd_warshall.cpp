#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void change_the_matrix(vector<vector<ll>>&mat , ll n, int idx){
    for(int i=1;i<=n; i++){
        if(i==idx){
            continue;
        }
        for(int j=1; j<=n; j++){
            if(j==idx){
                continue;;
            }
            else{
                mat[i][j] = min(mat[i][j] , mat[i][idx] + mat[idx][j]);
            }
        }
    }
}

int main(){
    ll n,m,k;
    cin>>n>>m>>k;

    vector<ll>mess(k);

    for(ll i=0;i<k; i++){
        cin>>mess[i]; 
    }

    vector<vector<ll>>v(n+1 , vector<ll>(n+1, INT_MAX));

    for(ll i=0;i<m; i++){
        ll a,b,wt;
        cin>>a>>b>>wt;

        v[a][b] = wt;
        v[b][a] = wt;

    }
    
    for(ll i=1;i<=n; i++){
        v[i][i] = 0;
    }

    for(ll i=1;i<=n; i++){
        change_the_matrix(v,n,i);
    }

    for(int i=1; i<=n; i++){
        ll minn = INT_MAX;
        for(auto ele: mess){
            minn = min(minn, v[i][ele]);
        }
        cout<<minn<<" ";
    }
}