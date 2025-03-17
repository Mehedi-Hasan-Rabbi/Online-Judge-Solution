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

ll find_max(ll x, ll n, ll m) {
    while (x > 1 and n + m > 0)
    {
        if (x % 2 == 0) {
            if (n > 0) n--;
            else if (m > 0) m--;

            x = x / 2;
        }
        else if (x % 2 == 1) {
            if (n > 0) {
                x = x / 2;
                n--;
            }
            else if (m > 0) {
                x = (x + 1) / 2;
                m--;
            }
        }
    }
    if (n > 0) x = 0;
    return x;
}

ll find_min (ll x, ll n, ll m) {
    while (x > 1 and n + m > 0)
    {   
        if (x % 2 == 0) {
            if (m > 0) m--;
            else if (n > 0) n--;

            x = x / 2;
        }
        else if (x % 2 == 1) {
            if (m > 0) {
                x = (x + 1) / 2;
                m--;
            }
            else if (n > 0) {
                x = x / 2;
                n--;
            }
        }
    }
    if (n > 0) x = 0;
    return x;
}

void solve()
{
    ll x, n, m; 
    cin >> x >> n >> m;

    ll maxi = x, mini = x;

    mini = find_min(x, n, m);
    maxi = find_max(x, n, m);

    cout << mini << " " << maxi << endl;
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