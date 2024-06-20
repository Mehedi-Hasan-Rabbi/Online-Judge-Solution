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
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    if ((a[1] + a[n]) % 2 == 0) a[1] = a[n];
    else a[n] = a[1];

    vector<pair<int, int>> ans;
    ans.push_back({1, n});
    for (int i = 2; i < n; i++) {
        if (a[i] == a[1]) continue;

        int val = a[i];
        if ((a[1] + val) % 2 == 1) {
            a[i] = a[1];
            ans.push_back({1, i});
        }
        else {
            a[i] = a[n];
            ans.push_back({i, n});
        }
    }

    cout << ans.size() << endl;
    for (auto &&u: ans) 
        cout << u.first << " " << u.second << endl;
    cout << endl;
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