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
    ll n, q; cin >> n >> q;
    vector<ll> a(n, 0), height(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) height[i] = a[i];
        else{
            height[i] = height[i - 1] + a[i];
            a[i] = max(a[i], a[i - 1]);
        } 
    }
    
    while (q--) {
        ll k; cin >> k;
        int idx = upper_bound(a.begin(), a.end(), k) - a.begin();
        
        if (idx == 0) cout << 0 << " ";
        else cout << height[idx - 1] << " ";
    }
    cout << endl;
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