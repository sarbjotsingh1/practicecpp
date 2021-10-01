#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a;
        set<int>s;
        while(a--)
        {
            cin>>b;
            s.insert(b);
        }
        cout<<s.size()<<endl;
    }
    return 0;
}