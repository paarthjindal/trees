#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    int n;
    cin>>n;

    int weight[n];
    vector<pair<int,int>>ans(n);
    for(int i=0;i<n; i++){
        cin>>weight[i];
        ans[i].first  = weight[i];//ans->i included
        ans[i].second = 0;          // i->not inclided.
    }
    
    vector<pair<int,int>>vp(n);
    for(int i=1;i<n; i++){  
        int a,b;
        cin>>a>>b;
        vp[i] = make_pair(a,b);//a->vertex no. ,  b->condition.
    }
    
    for(int i=n-1; i>0; i--){
        int index1 = i;
        int index2 = vp[i].first;
        if(vp[i].second == 0){
            ans[index2].first += ans[index1].second;
            ans[index2].second+= ans[index1].first;
        }
        else if(vp[i].second == 1){
            // ans[index2].first = max(max(ans[index1].first + ans[index2].first , ans[index1].second + ans[index2].first ) , ans[index1].first + ans[index2].second );
            // ans[index2].second = ans[index1].second + ans[index2].second ;
            ans[index2].first += ans[index1].first;
            ans[index2].second += ans[index1].second;
        }
        else if(vp[i].second == 2){
            ans[index2].first = max(ans[index1].first + ans[index2].second , ans[index1].second + ans[index2].first);
            ans[index2].second += ans[index1].second ;
        }
        ans[index2].first = max(ans[index2].first , ans[index2].second);
    }

    int anss = max(ans[0].first , ans[0].second);
    cout<<anss<<"\n";
}