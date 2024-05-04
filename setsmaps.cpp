#include <iostream>
using namespace std;
#include <set>
int main()
{
    set<int> s1; 
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s1.insert(x);
    }
    cout << s1.size() << endl;
    for( auto i :s1)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    set<int>::iterator itr;
    for (itr=s1.begin(); itr!=s1.end(); itr++)
    {
        cout<<*itr<<" "<<endl;   
    }
    return 0;
}