// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

#define endl               '\n'
#define efficient()        ios_base::sync_with_stdio(0); cin.tie(0);

void solve()
{
    int n;  cin >> n;

    map<string, int> freq;
    while (n--)
    {
        string s; cin >> s;

        if (freq[s] == 0) cout << "OK" << endl;
        else cout << s << freq[s] << endl;

        freq[s]++;
    }
    
}

int main(void)
{
    efficient();

    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}
