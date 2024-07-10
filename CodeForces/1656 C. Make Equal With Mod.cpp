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

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    int n; cin >> n;
    vector<int> a(n, 0);

    int one = 0, zero = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) one++;
        if (a[i] == 0) zero++;
    }
    sort(a.begin(), a.end());

    if (count(a.begin(), a.end(), a[0]) == n) cout << "YES" << endl;
    else if (one == 0) cout << "YES" << endl;
    else if (one >= 1 and zero == 0) {
        for (int i = 1; i < n; i++) {
            if (a[i - 1] + 1 == a[i]) {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
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