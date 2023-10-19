#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s; cin >> s;
    string test = s;

    reverse(test.begin(), test.end());

    if (s == test) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}