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
    int n, q; cin >> n >> q;
    string a; cin >> a;
    string b; cin >> b;

    vector<vector<int>> pref_A(26, vector<int>(n + 1)), pref_B(26, vector<int>(n + 1));
    for (int i = 0; i < n; i++) {
        int ch = a[i] - 'a';
        pref_A[ch][i + 1]++;
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 1; j <= n; j++)
            pref_A[i][j] = pref_A[i][j - 1] + pref_A[i][j];
    }
    for (int i = 0; i < n; i++) {
        int ch = b[i] - 'a';
        pref_B[ch][i + 1]++;
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 1; j <= n; j++)
            pref_B[i][j] = pref_B[i][j - 1] + pref_B[i][j];
    }

    while (q--) {
        int l, r; cin >> l >> r;

        int ans = 0, len = r - l + 1;
        for (int i = 0; i < 26; i++) {
            int count1 = pref_A[i][r] - pref_A[i][l - 1];
            int count2 = pref_B[i][r] - pref_B[i][l - 1];

            if (count1 > count2) {
                ans += abs(count1 - count2);
            }
        }

        cout << ans << endl;
    }
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