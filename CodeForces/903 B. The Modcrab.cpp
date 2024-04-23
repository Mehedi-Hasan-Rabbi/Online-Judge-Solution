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
    int h1, a1, c1; cin >> h1 >> a1 >> c1;
    int h2, a2; cin >> h2 >> a2;
    
    int need = (h2 / a1) + ((h2 % a1) != 0);
    int have = (h1 / a2) + ((h1 % a2) != 0);
    vector<int> ans;

    while (have < need) {
        h1 = h1 + c1;
        h1 = h1 - a2;
        have = (h1 / a2) + ((h1 % a2) != 0);
        ans.push_back(1);
    }

    while (need--) ans.push_back(2);

    cout << ans.size() << endl;
    for (auto &&u: ans) {
        if (u == 2) cout << "STRIKE" << endl;
        else cout << "HEAL" << endl;
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