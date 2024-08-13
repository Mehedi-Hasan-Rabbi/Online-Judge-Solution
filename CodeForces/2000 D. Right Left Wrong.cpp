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

void July_36_2024()
{
    int n; cin >> n;
    vector<ll> a(n + 1, 0), pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        pref[i] = pref[i - 1] + a[i];
    }

    string s; cin >> s;
    s = "#" + s;
    ll ans = 0;

    int l = 1, r = n;
    while (l < r) {
        if (s[l] != 'L' and s[r] != 'R') l++, r--;
        else if (s[l] == 'L' and s[r] == 'R') {
            ans += pref[r] - pref[l - 1];
            l++, r--;
        }
        else if (s[l] == 'L' and s[r] != 'R') r--;
        else if (s[l] != 'L' and s[r] == 'R') l++;
    }
    cout << ans << endl;
}

int main(void) {
    efficient();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        // cout << "Case " << tc << ": ";
        July_36_2024();
    }

    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}