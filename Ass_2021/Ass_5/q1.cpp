#include<iostream>
#include<vector>
#include<map>

#define ll long long int
using namespace std;

vector<bool>visited(1000000, false);

int find_no_of_path( int src, int dst,vector<vector<pair<int,int>>>v , int colour){
    if(src == dst){
        return 1;
    }    
    for(auto ele: v[src]){
        if( visited[ele.first] == false && ele.second == colour){ 

            visited[ele.first] = true;

            int x=find_no_of_path(ele.first,dst,v,ele.second);
      
            visited[ele.first] = false;
            if(x>0){
    
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int n,e;
    cin>>n>>e;

    vector<vector<pair<int,int>>>v(n+1);

    for(int i=0;i<e; i++){
        int a,b,c;
        cin>>a>>b>>c;

        pair<int,int>p1;
        p1.first = b;
        p1.second = c;

        pair<int,int>p2;
        p2.first = a;
        p2.second = c;

        v[a].push_back(p1);
        v[b].push_back(p2);
    }

    int q;
    cin>>q;
    
    while(q--){
        int a,b;
        cin>>a>>b;
     
        int ans= 0;

        vector<bool>color(e+1, false);//color for which all color are been traversed successfully.
        visited[a] = true;

        for(auto ele: v[a]){
            //ele is a pair.
            
            if(color[ele.second] == false ){
                visited[ele.first] = true;
                int x=find_no_of_path(ele.first,b,v,ele.second);
     
                if(x>0){
                    ans+=1;
                    color[ele.second] = true;
                }
                visited[ele.first] = false;
            }
        }
        cout<<ans<<"\n";
    }
}