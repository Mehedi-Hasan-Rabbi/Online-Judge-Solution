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

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> a(m, 0);
    for (int i = 0; i < m; i++) cin >> a[i];

    if (m == 1) {
        if (n <= 2) cout << 1 << endl;
        else cout << 2 << endl;
        return;
    }

    sort(a.begin(), a.end());
    vector<int> safe;
    for (int i = 1; i < m; i++) {
        if (i == m - 1) {
            int val = a[0] - 1;
            val += n - a[i];
            safe.push_back(val);
        }
        safe.push_back(a[i] - a[i - 1] - 1);
    }
    sort(safe.begin(), safe.end(), greater<int>());

    int eff_per_sec = 0; // Persecond effected house 2.
    for (auto &&u: safe) {
        u = max(0, u - eff_per_sec);
        if (u >= 3) {
            u = u - 1;
            eff_per_sec += 4; // Need 2 second. So, 2 * 2 = 4.
        }
        else if (u == 1 or u == 2) {
            u = 1;
            eff_per_sec += 2; // Nedd 1 second. So, 1 * 2 = 2;
        }
    }
    
    int tot_safe = accumulate(safe.begin(), safe.end(), 0);
    cout << n - tot_safe << endl;
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