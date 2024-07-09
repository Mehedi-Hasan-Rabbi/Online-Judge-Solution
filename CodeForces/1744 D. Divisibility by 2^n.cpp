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

int fector_two_count (int x)
{
    int cnt = 0;
    while (x % 2 == 0) {
        cnt++;
        x = x / 2;
    }
    return cnt;
}

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> idx_factor;
    int tot_two = 0;
    for (int i = 1; i <= n; i++) {
        tot_two += fector_two_count(a[i]);
        idx_factor.push_back(fector_two_count(i));
    }

    if (tot_two >= n) { cout << 0 << endl; return; }

    sort(idx_factor.begin(), idx_factor.end(), greater<int>());
    int ans = 0;
    for (auto u: idx_factor) {
        tot_two += u;
        ans++;

        if (tot_two >= n) { cout << ans << endl; return; }
    }

    if (tot_two >= n) cout << ans << endl;
    else cout << -1 << endl;

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