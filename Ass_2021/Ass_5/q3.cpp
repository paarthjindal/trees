#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void dfs(ll x , vector<vector<ll>>&v , vector<bool>&visited){
    visited[x] = true;

    for(auto ele: v[x]){
        if(visited[ele]== false) 
        {
            dfs(ele , v, visited);
        }
    }
    return ;
}

int main(){
    ll n,e;
    cin>>n>>e;

    vector<vector<ll>>v(n+1);
    vector<bool>visited1(n+1, false);
    vector<bool>visited2(n+1, false);

    vector<vector<ll>>v_d(n+1);
    // ll count = 0;//to 1 waale nodes.
    for(ll i=0;i<e;i++){
        ll a,b;
        cin>>a>>b;
  
        v[a].push_back(b);
        v_d[b].push_back(a);
    }
    
    dfs(1 ,v, visited1);
    for(ll i=1;i<n+1; i++){
        if(visited1[i] == false){
            cout<<"NO\n";
            return 0;
        }
    }
    dfs(1, v_d,visited2);
    for(ll i=1;i<n+1; i++){
        if(visited2[i] == false){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
}