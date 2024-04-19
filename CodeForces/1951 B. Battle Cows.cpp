// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "Code_Snippets/Debug.h"
#else
#define dbg
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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    k--;

    int ans = 0, pos = -1;
    for (int i = 0; i < k; i++) {
        if (a[i] > a[k]) {
            pos = i;
            break;
        }
    }

    // Check Swapping with index 0
    swap(a[0], a[k]);
    int win = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[0]) win++;
        else break;
    }
    ans = win;
    swap(a[0], a[k]);

    // Check Swapping with index pos
    if (pos != -1) {
        swap(a[pos], a[k]);
        win = 0;
        for (int i = pos + 1; i < n; i++) {
            if (a[i] < a[pos]) win++;
            else break;
        }
        if (pos != 0) win++;
        swap(a[pos], a[k]);
        ans = max(ans, win);
    }

    dbg(n, k, a);
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
