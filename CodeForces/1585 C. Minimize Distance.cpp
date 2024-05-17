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
    ll n, k; cin >> n >> k;
    vector<ll> pos, neg;
    for (ll i = 0; i < n; i++) {
        ll x; cin >> x;
        if (x < 0) neg.push_back(x * -1);
        else pos.push_back(x);
    }

    sort(pos.begin(), pos.end(), greater<ll>());
    vector<ll> pref(pos.size(), 1);
    for (ll i = 1; i < pref.size(); i++) pref[i] = pref[i - 1] + pref[i];
    
    ll ans = 0, done = k, l = 0, r = pos.size();
    while (l < r) {
        ll idx = upper_bound(pref.begin(), pref.end(), done) - pref.begin();
        ans += (pos[l] * 2);
        l = idx;
        done += k;
    }

    sort(neg.begin(), neg.end(), greater<ll>());
    vector<ll> pref_(neg.size(), 1);
    for (ll i = 1; i < pref_.size(); i++) pref_[i] = pref_[i - 1] + pref_[i];

    done = k, l = 0, r = neg.size();
    while (l < r) {
        ll idx = upper_bound(pref_.begin(), pref_.end(), done) - pref_.begin();
        ans += (neg[l] * 2);
        l = idx;
        done += k;
    }

    ll mx = INT64_MIN;
    if (neg.size() > 0) mx = max(mx, neg[0]);
    if (pos.size() > 0) mx = max(mx, pos[0]);

    cout << ans - mx << endl;
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