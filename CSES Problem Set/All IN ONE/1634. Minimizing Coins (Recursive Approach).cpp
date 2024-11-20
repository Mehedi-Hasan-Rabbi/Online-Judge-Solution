// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
#define endl               '\n'
#define efficient()        ios_base::sync_with_stdio(0); cin.tie(0);
 
/*---------------------------------------------------------------------------------------------------------------*/

const int mx = 1e6 + 123;
ll dp[mx];
vector<ll> coins;

ll minimizingCoins (ll currTotal)
{
    if (currTotal == 0) return 0;
    if (currTotal < 0) return 1e15;
    if (dp[currTotal] != -1) return dp[currTotal];

    ll result = 1e15;
    for (auto coin: coins) {
        ll val = 1 + minimizingCoins(currTotal - coin);
        result = min(result, val);
    }

    return dp[currTotal] = result;
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    ll n, total;
    cin >> n >> total;

    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        coins.push_back(x);
    }

    ll ans = minimizingCoins(total);

    cout << (ans < 1e15 ? ans : -1) << endl;
}
 
int main(void) {
    efficient();
 
    solve();
 
    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}