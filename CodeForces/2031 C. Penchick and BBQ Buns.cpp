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
    
    if (n % 2 == 0) {
        for (int i = 1; i <= n / 2; i++) {
            cout << i << " " << i << " ";
        }
        cout << endl;
    }

    else if (n <= 25) cout << -1 << endl;

    else {
        vector<int> ans(n + 1, 0);
        ans[1] = 1, ans[10] = 1, ans[26] = 1;
        ans[23] = 2, ans[27] = 2;

        int fill = 3;
        for (int i = 2; i <= 24; i++) {
            if (ans[i] == 0) {
                ans[i] = fill, ans[i + 1] = fill;
                ++fill;
            }
        }

        for (int i = 28; i <= n; i++) {
            if (ans[i] == 0) {
                ans[i] = fill, ans[i + 1] = fill;
                ++fill;
            }
        }

        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
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