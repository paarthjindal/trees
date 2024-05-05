#include<iostream>
#include<vector>
#include<map>

#define ll long long int
using namespace std;

vector<bool>visited(1000, false);
vector<vector<pair<int,int>>>v(1000);
vector<bool>color(1000);
int find_no_of_path(int e , int src, int dst,/*, vector<bool>&visited*/ int colour){
    if(src == dst){
        return 1;
    }    
    //vector<bool>color(e+1, false);//color for which all color are been traversed successfully.

    for(auto ele: v[src]){
        
        if( visited[ele.first] == false && ele.second == colour /*&& color[ele.second] == false*/ ){   
            visited[ele.first] = true;
            int x=find_no_of_path(e,ele.first,dst,/*visited,*/ele.second);
            // visited[ele.first] = false;
            // sum+=x;
            if(x>0){
                //color[ele.second] = true;
                return 1;
            }   
        }
    }
    return 0;
}

int main(){
    int n,e;
    cin>>n>>e;

    // vector<vector<pair<int,int>>>v(n+1);

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
        //vector<bool>visited(n+1, false);
        int ans= 0;

        //vector<bool>color(e+1, false);//color for which all color are been traversed successfully.
        // map<int,int>mp;
        visited[a] = true;

        for(auto ele: v[a]){
            //ele is a pair.
            
            if( visited[ele.first] == false && color[ele.second] == 0 ){
                visited[ele.first] = true;
                int x=find_no_of_path(e,ele.first,b,/*visited,*/ele.second);

                if(x>0){
                    ans+=1;
                    color[ele.second] = 1;
                }

                for(int i=0;i<1000; i++){
                    visited[i]  = false;
                }
            }
        }

        cout<<ans<<"\n";
        for(int i=0;i<1000; i++){
            visited[i]  = false;
            color[i] = 0;
        }
    }
}