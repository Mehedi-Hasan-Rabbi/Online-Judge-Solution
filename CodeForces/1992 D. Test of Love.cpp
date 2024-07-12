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
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    s = "L" + s + "L";

    vector<int> swim(n + 2, INT32_MAX);
    swim[n + 1] = 0;

    for (int i = n; i >= 0; i--)
    {
        if (s[i] == 'W' and swim[i + 1] < k) {
            swim[i] = swim[i + 1] + 1;
        }
        else if (s[i] == 'L') {
            int idx = i + 1;
            while (idx <= i + m and idx <= n + 1) {
                swim[i] = min(swim[i], swim[idx]);
                idx++;
            }
        }
        else continue;
    }
    
    if (swim[0] <= k) cout << "YES" << endl;
    else cout << "NO" << endl;
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