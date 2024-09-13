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

const ll MOD = 998'244'353;
const double PI = acos(-1);
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}

/*---------------------------------------------------------------------------------------------------------------*/

const int mx = 2e5 + 123;
ll fact[mx];

void July_36_2024()
{
    string s; cin >> s;
    int n = s.size();

    int k = 0, len = 0;
    char ch = s[0];
    ll ans = 1;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == ch) len++;
        else {
            ans = (ans * len) % MOD;
            len = 1;
            k++;
            ch = s[i];
        }
    }
    if (len > 0) {
        k++;
        ans = (ans * len) % MOD;
    }

    int min_op = n - k;
    ans = (ans * fact[n - k]) % MOD;

    cout << min_op << " " << ans << endl;
}

int main(void) {
    efficient();

    fact[0] = fact[1] = 1;
    for (int i = 2; i < mx; i++)
        fact[i] = ((fact[i - 1] % MOD) * (i % MOD)) % MOD;

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