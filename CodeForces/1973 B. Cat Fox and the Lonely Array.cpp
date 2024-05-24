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
vector<vector<int>> bin(1e5 + 10, vector<int> (31));

bool loneliness (int k, int n) {
    // Check first k elements common set bit
    vector<bool> common(31, 0);
    for (int bit = 0; bit < 32; bit++) 
        common[bit] = bin[k][bit] - bin[0][bit];

    // Check each subarray of k size has the same set bit as "common"
    for (int i = 1; i <= n - k + 1; i++) {
        vector<bool> set(31, 0);
        for (int bit = 0; bit < 32; bit++) {
            set[bit] = bin[i + k - 1][bit] - bin[i - 1][bit];
        }

        if (common != set) return false;
    }
    return true;
}

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    // Determine set bit of a[i]
    for (int i = 1; i <= n; i++) {
        for (int bit = 0; bit < 32; bit++) {
            if ( a[i] & (1 << bit) )
                bin[i][bit] = 1;
            else
                bin[i][bit] = 0;
        }

        // Prefix Sum
        for (int bit = 0; bit  < 32; bit++)
            bin[i][bit] = bin[i - 1][bit] + bin[i][bit];
    }

    int l = 1, r = n, ans = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (loneliness(mid, n) == true) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    
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