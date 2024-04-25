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
    double x, y, c; cin >> x >> y >> c;
    double l = 0, r = min(x, y);

    for (int i = 0; i < 60; i++) {
        double mid = l + (r - l) / 2;
        double d = mid;

        double h1 = sqrt( (x * x) - (d * d) );
        double h2 = sqrt( (y * y) - (d * d) );
        double c1 = (h1 * h2) / (h1 + h2);

        if (c1 < c) r = mid;
        else l = mid;
    }

    cout << l << endl;
}

int main(void) {
    efficient();
    fraction();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cout << "Case " << tc << ": ";
        solve();
    }

    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}