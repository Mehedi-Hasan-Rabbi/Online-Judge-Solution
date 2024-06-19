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

int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, -1, +1};

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    ll n, k; cin >> n >> k;

    ll mxPossible = 0, val = n;
    for (int i = 1; i <= n; i++) {
        mxPossible += abs(val - i);
        val--;
    }
    if (k % 2 == 1 or k > mxPossible) {
        cout << "NO" << endl;
        return;
    }

    vector<int> p(n + 1, 0); val = n;
    
    for (int i = 1; i <= ((n/2) + (n%2==1)); i++)
    {
        ll curr = abs(val - i) * 2LL;
        curr = min(curr, k);
        k = k - curr;
        curr = curr / 2LL;

        p[i] = curr + i;
        p[p[i]] = i;
        val--;
        if (k == 0) break;
    }
    for (int i = 1; i <= n; i++) {
        if (p[i] == 0)
            p[i] = i;
    }

    cout << "YES" << endl;
    for (int i = 1; i <= n; i++)
        cout << p[i] << " ";
    cout << endl;
}

int main(void) {
    // efficient();

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