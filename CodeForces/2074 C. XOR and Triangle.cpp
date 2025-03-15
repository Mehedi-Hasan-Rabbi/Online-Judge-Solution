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
 
const ll mod = 1e9 + 7; // 1000000007;
const double PI = 3.14159265358979323846;
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}
 
/*---------------------------------------------------------------------------------------------------------------*/
 
void solve()
{
    int x; cin >> x;
    vector<int> bit(32, 0);

    for (int i = 0; i < 32; i++) {
        if (x & (1 << i))
            bit[i] = 1;
    }

    int idx = -1;
    // Making the first set bit unset
    for (int i = 31; i >= 0; i--) {
        if (bit[i] == 1) {
            bit[i] = 0;
            idx = i - 1;
            break;
        }
    }

    // Making the first unset bit set
    for (int i = idx; i >= 0; i--) {
        if (bit[i] == 0) {
            bit[i] = 1;
            break;
        }
    }

    int y = 0;
    for (int i = 0; i < 32; i++) {
        if (bit[i] == 1)
            y += (1 << i);
    }

    int z = x ^ y;

    if ( (x + y) > z and (z + y) > x and (z + x) > y )
        cout << y << endl;
    else
        cout << -1 << endl;
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