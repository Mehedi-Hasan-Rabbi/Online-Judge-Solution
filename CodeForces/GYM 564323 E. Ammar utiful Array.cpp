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

const int mx = 2e5 + 5;

void solve()
{
    ll n; cin >> n;
    vector<ll> value(n), color(n);

    for (auto &u: value) cin >> u;
    for (auto &u: color) cin >> u;

    map<ll, vector<ll>> freq;
    for (int i = 0; i < n; i++) {
        freq[color[i]].push_back(value[i]);
    }

    for (auto [x, y]: freq) {
        vector<ll> arr = y;

        for (int i = 1; i < arr.size(); i++) {
            arr[i] = arr[i - 1] + arr[i];
        }
        arr.push_back(INT64_MAX);
        freq[x] = arr;
    }

    ll addition = 0LL;
    vector<ll> add_color(mx, 0LL);

    int q; cin >> q;
    while (q--) {
        ll tp, col, x;
        cin >> tp >> col >> x;

        if (tp == 1LL) {
            addition += x;
            add_color[col] += x;
        }
        else {
            ll target = x;
            ll idx = 0;
            ll low = 0, high = (ll) freq[col].size() - 1LL;
            
            while (low <= high)
            {
                ll mid = low + (high - low) / 2;

                ll store = freq[col][mid] + ((mid + 1) * (addition - add_color[col]));

                if (store <= target) {
                    idx = mid + 1;
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }

            cout << idx << endl;
        }
    }
}

int main(void) {
    efficient();

    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }

    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}