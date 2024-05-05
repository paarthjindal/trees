#include <bits/stdc++.h>
 
using namespace std;
typedef int ll;
// bool vis[50001] = {false};
ll dist_partial[50001][501], dist_full[50001][501];
vector<ll> adj[50001];
 
void dfs(ll start, ll &k, ll prev)
{
    for (auto ele : adj[start])
    {
        if (ele != prev)
            dfs(ele, k, start);
    }
    dist_partial[start][0] = 1;
    for (ll i = 1; i <= k; ++i)
    {
        dist_partial[start][i]=0;
        for (auto ele : adj[start])
        {
            if (ele != prev)
                dist_partial[start][i] += dist_partial[ele][i - 1];
        }
    }
}
 
void helper(ll start, ll &k, ll prev)
{
    for (ll l = 0; l <= k; ++l)
                dist_full[start][l] = dist_partial[start][l];
 
    if (prev != 0)
    {
        dist_full[start][1] += dist_full[prev][0];
        for (ll i = 2; i <= k; ++i)
            dist_full[start][i] += (dist_full[prev][i - 1] - dist_partial[start][i - 2]);
    }
 
    for (auto ele : adj[start])
    {
        if (ele != prev)
            helper(ele, k, start);
    }
}
 
int main()
{
        ll n, k;
        cin >> n >> k;
 
        for (ll i = 0; i < n - 1; ++i)
        {
            ll u, v;
            cin >> u >> v;
 
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
 
        dfs(1, k, 0);
        
        helper(1, k, 0);
 
        ll no_pairs = 0;
        for (ll j = 1; j <= n; ++j)
        {
            no_pairs += dist_full[j][k];
        }
        cout << (no_pairs / 2 )<< endl;
    return 0;
}