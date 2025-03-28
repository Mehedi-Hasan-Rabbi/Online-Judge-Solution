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
const int mx = 2e5 + 123;

string t, p, store;
int n , m;
int a[mx];

bool isSubsequence(int val) {   
    t = store;
    for (int i = 1; i <= val; i++)
        t[a[i] - 1] = '#'; // # means removed

    for (int i = 0, j = 0; i < n; i++) {
        if (t[i] == p[j]) {
            j++;
            if (j == m) return true;
        }
    }
    return false;
}

void solve()
{
    cin >> t >> p;
    n = t.size(), m = p.size();
    for (int i = 1; i <= n; i++) cin >> a[i];

    store = t;
    int l = 0, r = n, ans;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (isSubsequence(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans << endl;
}

int main(void) {
    // efficient();

    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }

    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}