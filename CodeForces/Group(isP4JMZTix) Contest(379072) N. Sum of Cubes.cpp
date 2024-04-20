// In the name of Allah the merciful.
// Link: https://codeforces.com/group/isP4JMZTix/contest/379072/problem/N
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

const int mx = 1e4 + 123;
ll cube[mx];

void solve()
{
    ll x; cin >> x;
    int lim = 1e4;

    for (ll i = 1; i <= lim; i++) {
        ll b = (i * i * i);
        ll a = x - b;

        bool isExists = binary_search(cube+1, cube+lim, a);
        if (isExists) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main(void) {
    efficient();

    for (ll i = 1; i <= 1e4; i++) cube[i] = (i * i * i);

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