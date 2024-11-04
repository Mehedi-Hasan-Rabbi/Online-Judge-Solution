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

// Probability of having a girl (g per billion)
// Probability of having a boy (10^9 - g per billion)

/*
Expected number of boys: If the probability of having a boy is 𝑝 = (10^9 − 𝑔 / 10^9), then the expected number of boys in a large sequence of births is directly proportional to this probability.

Expected number of girls: Similarly, if the probability of having a girl is q = (𝑔 / 10^9), then expected number of girls in the sequence is proportional to this probability.

So, The ratio of expected boys to expected girls can be calculated as => (Expected number of boys / Expected number of girls)
                                                                      => p/q
                                                                      => (10^9 − 𝑔 / g)

e.g. Probability of having a girl = g = 500000000
     Probability of having a boy = 10^9 - g = 500000000

     So the ratio of expected boys to expected girls is:
        (10^9 − 𝑔 / g) = 500000000/500000000 = 1/1

*/

void solve()
{
    ll x, y, g; cin >> x >> y >> g;
    ll not_g = 1e9 - g;

    ll GCD = gcd(not_g, g);

    cout << (not_g / GCD) << "/" << (g / GCD) << endl;
}

int main(void) {
    efficient();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cout << "Case " << tc << ": ";
        solve();
    }

    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}