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

double area_of_triangle (double a, double b, double c) {
    double s = (a + b + c) / 2;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}

void solve()
{
    double AB, AC, BC, R;
    cin >> AB >> AC >> BC >> R;

    // Area of the Triangle ABC
    double AreaOf_ABC = area_of_triangle (AB, AC, BC);

    double l = 0, r = AB;
    for (int i = 0; i < 60; i++) {
        double mid = l + (r - l) / 2;

        // If a line is drawn parallel to one side of a triangle to intersect the other two side in distinct points, 
        // the other two sides are divided in the same ratio.
        // So, (AD/AB) == (AE/AC) == (DE/BC)
        double AD = mid;
        double AE = (AD * AC) / AB;
        double DE = (AD * BC) / AB;

        // Area of the Triangle ADE
        double AreaOf_ADE = area_of_triangle (AD, AE, DE);

        // Area of the trapezium BDEC
        double AreaOf_BDEC = AreaOf_ABC - AreaOf_ADE;

        // Ration of triangle and trapezium
        double ration = AreaOf_ADE / AreaOf_BDEC;

        if (ration < R) l = mid;
        else r = mid;
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