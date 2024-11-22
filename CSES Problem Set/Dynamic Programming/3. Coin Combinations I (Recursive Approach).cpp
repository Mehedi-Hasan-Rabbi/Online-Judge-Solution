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

const int mx = 1e6 + 123;
ll dp[mx];
vector<ll> coins;

ll coinCobinations (ll currTotal)
{   
    if (currTotal == 0) return 1;
    if (currTotal < 0) return 0;
    if (dp[currTotal] != -1) return dp[currTotal];


    ll take = 0;
    for (auto coin: coins) {
        take = Modular_Addition(take, coinCobinations(currTotal - coin));
    }

    return dp[currTotal] = take;
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

    cout << coinCobinations(total) << endl;
}
 
int main(void) {
    efficient();
 
    solve();
 
    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}