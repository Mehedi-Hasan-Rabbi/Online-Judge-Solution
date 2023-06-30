#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    long long int factorial = 1;

    for (int i=2; i<=n; i++)
    {
        factorial = factorial * i;
    }
    cout << factorial << endl;
}

int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
