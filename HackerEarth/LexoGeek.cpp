#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;

    if (next_permutation(s.begin(), s.end()))
        cout << s << endl;
    else cout << "no answer" << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}