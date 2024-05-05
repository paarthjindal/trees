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

ll find_min_vertex(vector<ll>distance , int n, vector<bool>visited){

    ll minn = INT_MAX;

    ll idx ;

    for(int i=0;i<n; i++){
        if(distance[i] < minn && visited[i] == false){
            idx = i;
            minn = distance[i];
        }
    }
    return idx;
}

void minimum_spanning_tree(vector<vector<pair<ll,ll>>>v, ll n){

    vector<bool>visited(n, false);
    vector<ll>distance(n, INT_MAX);

    distance[0] = 0;
    priority_queue< pair<ll ,ll >, vector<pair<ll,ll>> , greater<pair<ll,ll>> >p;//min heap
    p.push({0,0});
    
    while(!p.empty()){
        //int idx = find_min_vertex(visited , dist, n);
        pair<int,int> curr_pair = p.top();
        p.pop();
        visited[curr_pair.second] = true;
        for(auto ele: v[curr_pair.second]){
            if(visited[ele.first] == false && (ele.second) < distance[ele.first])
            {
                distance[ele.first] = ele.second ;
               
                p.push(make_pair(distance[ele.first] , ele.first));
            }
        }
    }
    // for(auto ele: v[idx]){
    //     ll edge_weight = ele.second;
    //     ll num = ele.first;

    //     if( visited[num] == false && distance[num] > edge_weight ){
    //         distance[num] = edge_weight;
    //     } 
    // }
    ll sum=0;
    for(int i=0;i<n; i++){
        sum+=distance[i];
    }

    cout<<sum<<"\n";
}

bool cmp1(vector<ll>&v1, vector<ll>&v2){
    return v1[0]<v2[0];
}

bool cmp2(vector<ll>&v1, vector<ll>&v2){
    return v1[1]<v2[1];
}

int main(){
    ll n;
    cin>>n;
    //lets number all the nodes from 0->no.of nodes
    //no.of nodes = n
    vector<vector<ll>>vertices(n,vector<ll>(3));
    vector<vector<ll>>vertices2(n,vector<ll>(3));
    for(int i=0;i<n; i++){
        ll a,b;
        cin>>a>>b;

        vertices[i] ={a,b,i};
        vertices2[i] ={a,b,i};
    }

    vector<vector<pair<ll,ll>>>v(n);
    sort(vertices.begin(), vertices.end(),  cmp1);
    sort(vertices2.begin(),vertices2.end(), cmp2);

    for(int i=0;i<n;i++){
        if(i==0){
            ll curr_idx = vertices[i][2];
            ll minn = min( abs(vertices[i][0] - vertices[i+1][0]) , abs(vertices[i][1] - vertices[i+1][1]));
            v[curr_idx].push_back( {vertices[i+1][2]  ,  minn} ); 
        }
        else if(i==n-1){
            ll curr_idx = vertices[i][2];
            ll minn = min( abs(vertices[i][0] - vertices[i-1][0]) , abs(vertices[i][1] - vertices[i-1][1]));
            v[curr_idx].push_back( {vertices[i-1][2]  ,  minn} ); 
        }
        else{
            ll curr_idx = vertices[i][2];
            ll minn = min( abs(vertices[i][0] - vertices[i-1][0]) , abs(vertices[i][1] - vertices[i-1][1]));
            v[curr_idx].push_back( {vertices[i-1][2]  ,  minn} ); 

            curr_idx = vertices[i][2];
            minn = min( abs(vertices[i][0] - vertices[i+1][0]) , abs(vertices[i][1] - vertices[i+1][1]));
            v[curr_idx].push_back( {vertices[i+1][2]  ,  minn} ); 
        }
    }

    for(int i=0;i<n;i++){
        if(i==0){
            ll curr_idx = vertices2[i][2];
            ll minn = min( abs(vertices2[i][0] - vertices2[i+1][0]) , abs(vertices2[i][1] - vertices2[i+1][1]));
            v[curr_idx].push_back( {vertices2[i+1][2]  ,  minn} ); 
        }
        else if(i==n-1){
            ll curr_idx = vertices2[i][2];
            ll minn = min( abs(vertices2[i][0] - vertices2[i-1][0]) , abs(vertices2[i][1] - vertices2[i-1][1]));
            v[curr_idx].push_back( {vertices2[i-1][2]  ,  minn} ); 
        }
        else{
            ll curr_idx = vertices2[i][2];
            ll minn = min( abs(vertices2[i][0] - vertices2[i-1][0]) , abs(vertices2[i][1] - vertices2[i-1][1]));
            v[curr_idx].push_back( {vertices2[i-1][2]  ,  minn} ); 

            curr_idx = vertices2[i][2];
            minn = min( abs(vertices2[i][0] - vertices2[i+1][0]) , abs(vertices2[i][1] - vertices2[i+1][1]));
            v[curr_idx].push_back( {vertices2[i+1][2]  ,  minn} ); 
        }
    }

    minimum_spanning_tree(v, n);
}