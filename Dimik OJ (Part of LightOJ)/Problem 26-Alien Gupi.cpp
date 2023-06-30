#include<bits/stdc++.h>
using namespace std;

void solve()
{
    double X;
    cin >> X;

    int count = 0;
    while(X>1.0)
    {
        X = X/2;
        count++;
    }
    cout << count << " days" << '\n';
}

int main(void)
{
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
