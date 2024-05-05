#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int countt = 0;
vector<vector<int>>v(50002);
vector<vector<int>>distance_mat(50002, vector<int>(1002));

void dfs(int src, int par, int k)
{
    distance_mat[src][0] = 1;//distance with itself is at 0, so a node at distance 0.

    for (auto ele : v[src]) {
        if (ele != par) {

            dfs(ele, src, k);
            for (int i=1; i<k+1; i++){
                countt += distance_mat[ele][i-1]*distance_mat[src][k-i];
            }
            for (int i=1; i<k+1; i++){
                distance_mat[src][i] += distance_mat[ele][i-1];
            }

        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<50002; i++){
            v[i].clear();
            for(int j=0;j<1002; j++){
                distance_mat[i][j] = 0;
            }
        }
        countt = 0;
        int n,k;
        cin>>n>>k;
        
        
        for(int i=0;i<n-1; i++){
            int a,b;
            cin>>a>>b;

            v[a].push_back(b);
            v[b].push_back(a);
        }
        if(k==0){
            cout<<n<<"\n";
            continue;
        }
        int start = 1;
        int parent = -1;

        
        dfs( start, parent, k);
        cout << countt<<"\n";
        
        
    }
}