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

double distance (double x1, double y1, double x2, double y2) {
    return sqrt( ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)) );
}

void solve()
{
    double px, py; cin >> px >> py;
    double ax, ay; cin >> ax >> ay;
    double bx, by; cin >> bx >> by;

    double l = 0, r = 1e6;
    for (int i = 0; i < 60; i++) {
        double mid = l + (r - l) / 2;

        bool pointO = false, pointP = false, AB_connect = false;

        double dis_AB = distance(ax, ay, bx, by);
        double dis_AO = distance(ax, ay, 0, 0);
        double dis_AP = distance(ax, ay, px, py);
        double dis_BO = distance(bx, by, 0, 0);
        double dis_BP = distance(bx, by, px, py);

        // Checking if point O and P is under Radius of A
        if (dis_AO <= mid) pointO = true;
        if (dis_AP <= mid) pointP = true;
        if (pointO and pointP) { 
            r = mid;
            continue;
        }
        // Checking if point O and P is under Radius of B
        pointO = false, pointP = false;
        if (dis_BO <= mid) pointO = true;
        if (dis_BP <= mid) pointP = true;
        if (pointO and pointP) { 
            r = mid;
            continue;
        }

        // If not, then Point A, B must be connectd and Point O, P have to be under some point
        if (mid * 2 >= dis_AB) AB_connect = true;
        if (dis_AO <= mid) pointO = true;
        if (dis_AP <= mid) pointP = true;

        if (dis_BO <= mid) pointO = true;
        if (dis_BP <= mid) pointP = true;

        if (pointO and pointP and AB_connect) r = mid;
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
        // cout << "Case " << tc << ": ";
        solve();
    }

    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}