// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/Debug.h"
#else
#define dbg(...)
#endif

typedef long long ll;
typedef unsigned long long ull;

#define endl               '\n'
#define efficient()        ios_base::sync_with_stdio(0); cin.tie(0);
#define fraction()         cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return abs(a) * ( abs(b) / gcd ( a, b ) ); }

int dx[] = {+1, -1, 0, 0, +1, +1, -1, -1};
int dy[] = {0, 0, -1, +1, +1, -1, +1, -1};

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}

/*---------------------------------------------------------------------------------------------------------------*/

const int mx = 2e5 + 123;
long long fact[mx];

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

long long nCr (ll n, ll r)
{
    if (r > n) return 0;

    ll a = fact[n];
    ll b = ((fact[n - r] % MOD) * (fact[r] % MOD)) % MOD;
    b = binpow(b, (MOD - 2)); // Inverse Modulo

    ll ans = ((a % MOD) * (b % MOD)) % MOD;
    return ans;
}

void July_36_2024()
{
    ll n, k; cin >> n >> k;
    vector<ll> a(n, 0);

    ll tot_one = 0, tot_zero = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) tot_one++;
        else tot_zero++;
    }

    // for a subsequence of k(odd) where median is 1, there must be number of 1's > number of 0's;
    // exp: 00111 -> median 1; 00011 -> median 0; 01111 -> median 1;
    // So, minimum number of one is : (k / 2) + 1;
    int need_one = (k / 2) + 1;
    if (tot_one < need_one) {
        cout << 0 << endl;
        return;
    }

    // From a set of n number now many ways we can take k number: nCk
    // So, from total number of 1's (tot_one) how many ways we can take required number of 1's(need_one): tot_one C need_one
    // And to fill the remaining k we need 0's: tot_zero C (k - need one)
    // So, the ans is : (tot_one C need_one) * (tot_zero C (k - need one))
    // We have calculated for exactly for the minimum number of 1's. But, if the number of number of is more than need_one then it is also a valid subsequences;
    // So, we need a loop to iterate from need_one to total number of one;
    
    ll ans = 0;
    for (ll i = need_one; i <= min(tot_one, k); i++)
    {
        // nCr for 1's
        ll n = tot_one, r = i;
        ll x = nCr(n, r);

        // nCr for 0's
        n = tot_zero, r = k - i;
        ll y = nCr(n, r);
        
        ll res = ((x % MOD) * (y % MOD)) % MOD;
        ans = ((ans % MOD) + (res % MOD)) % MOD;
    }

    cout << ans << endl;
}

int main(void) {
    efficient();
    fact[0] = 1;
    for (ll i = 1; i < mx; i++) {
        fact[i] = ((fact[i - 1] % MOD) * (i % MOD)) % MOD;
    }
    
    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        // cout << "Case " << tc << ": ";
        July_36_2024();
    }

    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}

// For more explanation watch this: https://youtu.be/XfOBx5yhTmk?t=3931