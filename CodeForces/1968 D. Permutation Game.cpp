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

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    ll n, k, pos_b, pos_s; cin >> n >> k >> pos_b >> pos_s;
    vector<ll> p(n + 1, 0), a(n + 1, 0);
    for (ll i = 1; i <= n; i++) cin >> p[i];
    for (ll i = 1; i <= n; i++) cin >> a[i];

    ll bodya = -1, curr = 0;
    for (ll i = 1; i <= min(k, n); i++) {
        curr = curr + a[pos_b];
        ll mul = (a[pos_b] * (k - i));

        pos_b = p[pos_b];
        bodya = max(bodya, (curr + mul));
    }

    ll sasha  = -1; curr = 0;
    for (ll i = 1; i <= min(k, n); i++) {
        curr = curr + a[pos_s];
        ll mul = (a[pos_s] * (k - i));

        pos_s = p[pos_s]; 
        sasha = max(sasha, (curr + mul));
    }

    if (bodya > sasha) cout << "Bodya" << endl;
    else if (sasha > bodya) cout << "Sasha" << endl;
    else cout << "Draw" << endl;
}

int main(void) {
    efficient();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }

    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}