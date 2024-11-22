// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
#define endl               '\n'
#define efficient()        ios_base::sync_with_stdio(0); cin.tie(0);
 
const ll mod = 1e9 + 7; // 1000000007;
 
/*---------------------------------------------------------------------------------------------------------------*/

ll Modular_Addition(ll x, ll y) {
    x = x % mod; y = y % mod;
    return (((x + y) % mod) + mod) % mod;
}

void solve()
{
    ll n, total;
    cin >> n >> total;

    vector<ll> coins;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        coins.push_back(x);
    }

    vector<ll> dp(total + 5, 0);

    // Base Condition
    dp[0] = 1;

    for (ll currTotal = 1; currTotal <= total; currTotal++) {
        ll val = 0;
        for (auto coin: coins) {
            if ((currTotal - coin) >= 0) {
                // Transition
                val = Modular_Addition(val, dp[currTotal - coin]);
            }
        }
        dp[currTotal] = val;
    }

    cout << dp[total] << endl;
}
 
int main(void) {
    efficient();
 
    solve();
 
    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}