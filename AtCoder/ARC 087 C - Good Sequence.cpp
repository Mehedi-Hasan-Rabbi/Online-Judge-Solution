// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

#define endl               '\n'
#define efficient()        ios_base::sync_with_stdio(0); cin.tie(0);

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    int n; cin >> n;

    map<int, int> freq;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        freq[x]++;
    }
    
    int ans = 0;
    for (auto &&i : freq)
    {
        if (i.second >= i.first) ans += (i.second - i.first);
        else ans += i.second;
    }
    
    cout << ans << endl;
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
