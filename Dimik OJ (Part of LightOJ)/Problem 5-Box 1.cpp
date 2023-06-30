#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout << "*";
        cout << endl;
    }
}

int main(void)
{
    int t;
    cin >> t;

    while(t--)
    {
        solve();
        if (t != 0)
            cout << endl;
    }
    return 0;
}
