#include <iostream>
using namespace std;
#include <map>
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    map <int,int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for( auto i:mp)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }

    return 0;
}