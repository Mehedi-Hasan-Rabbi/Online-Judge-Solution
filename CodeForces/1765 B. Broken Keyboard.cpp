// In the name of Allah the merciful.
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0; i<n; )
    {
        if(i%3 == 0 )
        {
            i++;
            continue;
        }
        else
        {
            if(s[i] == s[i+1])
            {
                i=i+3;
                continue;
            }
            else
            {
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
}
int main()
{
    int t, n;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
