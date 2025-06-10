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
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int a1 = a[1], a2 = a[2], x, y;
    y = (2 * a1) - a2;

    if (y % (n + 1) != 0 or y < 0) {
        cout << "NO" << endl;
        return;
    }
    else {
        y = y / (n + 1);
        x = a1 - (n * y);

        if (x < 0) {
            cout << "NO" << endl;
            return;
        }
    }

    for (int i = 1; i <= n; i++) {
        a[i] = a[i] - (i * x) - ( (n - i + 1) * y );

        if (a[i] == 0) continue;
        else {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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

/*
Let's say we need x times type-1 and y times type-2 operation.
So, we can say write that,

For index = 1,
    a[1] - (i * x) - ((n - i + 1) * y) = 0
    => a[1] - x - ny = 0
    => a[1] = x + ny ---------------------------(1)
    
For index = 2,
    a[2] - (i * x) - ((n - i + 1) * y) = 0
    => a[2] - 2x - (n - 1)y = 0
    => a[2] = 2x + (n - 1)y --------------------(2)

and so on......

    Now, If some how we can calculate x, y then the problem is simple. We just need to check that this x, y is applied to all the indexes.

    (1)*2 - (2),
    ----------------
                    2a[1] = 2x + 2ny
                    a[2]  = 2x  (n - 1)y
    -------------------------------------------
    Subtraction, 2a[1] - a[2] = 2ny - (n - 1)y
            =>  2a[1] - a[2] = y(n + 1)
            => y = (2a[i] - a[2]) / (n + 1);

            and,
            x = a[1] - ny;

    if x or y or both become negative then it is not possible.    
*/