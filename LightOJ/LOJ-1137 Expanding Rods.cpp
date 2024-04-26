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
    double L, n, c; cin >> L >> n >> c;
    double L_prime = (1.0 + (n * c)) * L;

    double l = 0, r = 1e18;
    while (r - l > eps) {
        double mid = l + (r - l) / 2;

        double radius = mid;
        double new_L = (2.0 * radius * asin(L / (2.0 * radius)));

        if (new_L < L_prime) r = mid;
        else l = mid;
    }

    double radius = l;
    double d = sqrt( (radius * radius) - ((L/2) * (L/2)) );
    double h = radius - d;

    cout << h << endl;
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