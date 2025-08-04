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
    int n, x; cin >> n >> x;
    vector<int> bin(35, 0);

    int element = 0;
    for (int bit = 0; bit < 32; bit++) {
        if (x & (1 << bit)) {
            bin[bit] = 1;
            element++;
        }
    }

    if (n == 1 and x == 0) { cout << -1 << endl; return; }
    if (element >= n) { cout << x << endl; return; }

    int left = n - element;
    if (left % 2 == 1) left++;

    if (bin[0] == 1) {
        if ( n - 1 >= left ) {
            bin[0] += left;
        }
        else {
            bin[0] += (left - 2);
            bin[1] += 2;
        }
    }
    else {
        if (left <= n) bin[0] += left;
        else {
            bin[0] += left - 2;
            bin[1] += 2;
        }
    }

    int ans = 0;
    for (int i = 0; i < 32; i++) {
        if (bin[i]) {
            ans += ((1 << i) * bin[i]);
        }
    }

    cout << ans << endl;
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