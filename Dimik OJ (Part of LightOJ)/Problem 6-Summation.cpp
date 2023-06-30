#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, sum = 0;
    cin >> n;

    for (int i=5; i>=1; i--)
    {
        if (i==5 || i==1)
        {
            sum = sum + (n%10);
        }
        n = n/10;
    }
    cout << "Sum = " << sum << endl;
}

int main(void)
{
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }
    return 0;
}
