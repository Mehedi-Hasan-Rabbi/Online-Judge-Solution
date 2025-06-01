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
 
const ll mod = 998244353;
const double PI = 3.14159265358979323846;
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}
 
/*---------------------------------------------------------------------------------------------------------------*/

const int mx = 1e5 + 123;
int pow_of_two[mx];

int Modular_Addition(int x, int y) {
    x = x % mod; y = y % mod;
    return (((x + y) % mod) + mod) % mod;
}
int Modular_Multiplication(int x, int y) {
    x = x % mod; y = y % mod;
    return (((x * y) % mod) + mod) % mod;
}

void solve()
{
    int n; cin >> n;
    vector<int> p(n, 0), q(n, 0);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> q[i];

    vector<int> ans;
    int mx_p = INT32_MIN, mx_q = INT32_MIN;
    int idx_p = -1, idx_q = -1;

    for (int i = 0; i < n; i++) {
        if (p[i] > mx_p) mx_p = p[i], idx_p = i;
        if (q[i] > mx_q) mx_q = q[i], idx_q = i;

        int res = -1;
        if (mx_p > mx_q) {
            int pair_val = q[i - idx_p];
            res = Modular_Addition(pow_of_two[mx_p], pow_of_two[pair_val]);
        }
        else if (mx_p < mx_q) {
            int pair_val = p[i - idx_q];
            res = Modular_Addition(pow_of_two[mx_q], pow_of_two[pair_val]);
        }
        else {
            int pair_val_p = q[i - idx_p];
            int pair_val_q = p[i - idx_q];
            
            int take = max(pair_val_p, pair_val_q);
            res = Modular_Addition(pow_of_two[mx_p], pow_of_two[take]);
        }

        ans.push_back(res);
    }

    for (auto u: ans) cout << u << " "; cout << endl;
}
 
int main(void) {
    efficient();

    pow_of_two[0] = 1;
    for (int i = 1; i < mx; i++) {
        pow_of_two[i] = Modular_Multiplication(pow_of_two[i - 1], 2);
    }
 
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