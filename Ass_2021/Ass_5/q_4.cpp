//to find the minimum distance of all the vertices from a single vertex.

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// int find_min_vertex(vector<bool>visited , vector<int>dist, int n){
//     int minn = INT_MAX;
//     int min_idx ;
//     for(int i=0; i<n; i++){
//         if(visited[i] == false && dist[i] < minn){
//             minn = dist[i];
//             min_idx = i;
//         }
//     }
//     return min_idx;
// }


void dijkstra_algo_using_heaps(int n, int e, vector<vector<pair<int,int>>>&v, vector<int>&mess){
    vector<bool>visited(n+1, false);
    vector<int>dist(n+1, INT_MAX);
   
    
    priority_queue< pair<int, int >, vector<pair<int,int>> , greater<pair<int,int>> >p;//min heap

    for(auto ele: mess){
        dist[ele] = 0;
        p.push(make_pair(0 , ele));// weight and vertex
    }
    
    while(!p.empty()){
        //int idx = find_min_vertex(visited , dist, n);
        pair<int,int> curr_pair = p.top();
        p.pop();
        visited[curr_pair.second] = true;
        for(auto ele: v[curr_pair.second]){
            if(visited[ele.first] == false && (ele.second + curr_pair.first) < dist[ele.first])
            {
                dist[ele.first] = ele.second + curr_pair.first;
               
                p.push(make_pair(dist[ele.first] , ele.first));
            }
        }
    }
    for(int i=1;i<n+1; i++){
        
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n,e,k;
    cin>>n>>e>>k;

    vector<int>mess;

    for(int i=0;i<k; i++){
        int x;
        cin>>x;
        mess.push_back(x);
    }
    vector<vector<pair<int,int>>>v(n+1);
    for(int i=0;i<e; i++){
        int a,b,c;
        cin>>a>>b>>c;

        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));

    }

    dijkstra_algo_using_heaps(n,e,v, mess);
}