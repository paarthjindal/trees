//minimum spanning tree
//we have to join all the vertices, with minimum possible no. edges
//if no. of vertices is v, no. of edgtes is v-1
//graph must be single component
//in primes algo, we will find the minimum weight vertex for a respecttive parent, 
//and hen join the parent with that vertex, 
//also we will traverse all its()parent) linked nodes, and set there minimum distance. 

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll find_min_distance_vertex(vector<bool>visited, vector<ll>dist, ll n){
    ll minn = INT_MAX;
    ll idx;
    for(int i=0;i<n ; i++){
        if( visited[i] == false && dist[i] < minn){
            minn = dist[i];
            idx = i;
        }
    }
    return idx;
}

void find_min_spanning_tree(ll n, vector<vector<ll>>&v){

    vector<bool>visited(n,false);
    vector<ll>dist(n, INT_MAX);
    dist[0] = 0;
    vector<ll>parent(n);
    parent[0] = -1;
    //no_of edgrs will be n-1.
    for(ll i=0;i<n-1; i++){

        ll idx = find_min_distance_vertex(visited, dist,n);
        visited[idx] = true;

        for(ll j=0;j<n; j++){
            if(v[idx][j] !=0 && visited[j]==false && v[idx][j] < dist[j]){
                parent[j]= idx;
                dist[j] = v[idx][j];
            }
        }
    }

    ll sum = 0;
    for(ll i=0;i<n; i++){
        sum+= v[parent[i]][i];
    }
    cout<<sum<<"\n";
}

int main(){
    ll n;
    cin>>n;
    //lets number all the nodes from 0->no.of nodes
    //no.of nodes = n
    vector<pair<ll,ll>>vertices(n);
    for(int i=0;i<n; i++){
        ll a,b;
        cin>>a>>b;

        vertices[i] =(make_pair(a,b));
    }

    vector<vector<ll>>v(n , vector<ll>(n, 0));

    for(ll i=0;i<n; i++){
        for(ll j=0;j<n; j++){

            ll minn= min( abs(vertices[i].first - vertices[j].first ) , abs(vertices[i].second - vertices[j].second));
            v[i][j] = minn;
            v[j][i] = minn;
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n; j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    
    find_min_spanning_tree(n, v);
}
      