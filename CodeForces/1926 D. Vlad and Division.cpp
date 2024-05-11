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
    int n; cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    map<int, int> freq;
    for (int i = 0; i < n; i++) freq[a[i]]++;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int group_member = 0;
        for (int bit = 0; bit < 31; bit++) {
            if ( !(a[i] & (1 << bit)) ) {
                group_member += (1 << bit);
            }
        }
        
        if (freq[a[i]] > 0 and freq[group_member] > 0) {
            ans++;
            freq[a[i]]--, freq[group_member]--;
        }
    }

    for (auto [key, val]: freq) ans += val;

    cout << ans << endl;
}

int main(void) {
    // efficient();

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