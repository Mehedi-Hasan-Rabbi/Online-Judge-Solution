// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl               '\n'
#define mem(a, b)          memset(a, b, sizeof(a) )
#define efficient()        ios_base::sync_with_stdio(0); cin.tie(0);

const ll MOD = 10000007;

/*---------------------------------------------------------------------------------------------------------------*/
ll dp[10123];
ll a, b, c, d, e, f;

ll fn(ll n) {
    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return c;
    if (n == 3) return d;
    if (n == 4) return e;
    if (n == 5) return f;

    if (dp[n] != -1) return dp[n];

    // ll res = ( (fn(n-1)%MOD) + (fn(n-2)%MOD) + (fn(n-3)%MOD) + (fn(n-4)%MOD) + (fn(n-5)%MOD) + (fn(n-6)%MOD) ) % MOD;
    // Or, 
    // ll res = fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6);

    ll res = fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6);
    dp[n] = res % MOD;

    return dp[n];
}

int main()
{
    efficient();
    int T; cin >> T;
    ll n;
    for (int tc = 1; tc <= T; tc++)
    {
        memset(dp, -1, sizeof(dp));
        cin >> a >> b >> c >> d >> e >> f >> n;

       cout << "Case " << tc << ": " << fn(n) % MOD << endl;
       // If we don't mod fn(n) then there will be wrong answer. Don't Know why
    }
}