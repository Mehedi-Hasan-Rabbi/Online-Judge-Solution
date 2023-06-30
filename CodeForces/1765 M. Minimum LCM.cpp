#include <bits/stdc++.h>
using namespace std;

int t, n;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        int prime = n;
        for (int d = 2; d * d <= n; ++d)
            if (n % d == 0)
            {
                prime = d;
                break;
            }
        int piece = n / prime;
        cout << piece << " " << n - piece << '\n';
    }
    return 0;
}

