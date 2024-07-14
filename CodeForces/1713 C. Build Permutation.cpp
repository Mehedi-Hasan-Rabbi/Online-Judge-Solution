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

const int mx = 2e5 + 123;
bool p_sq[mx];
vector<int> pref(mx, 0);

bool isPerfectSquare(int x)
{
    if (x == 0) return true;
    if (x > 0) {
        int sr = sqrt(x + 1);
        return (sr * sr == x);
    }
    return false;
}

void solve()
{
    int n; cin >> n;
    vector<int> permu(n, -1);

    for (int i = n - 1; i >= 0; i--) {
        if (p_sq[i] == true) {
            int val = i;
            for (int j = 0; j <= i; j++) {
                permu[j] = val;
                val--;
            }
            i = 0;
        }
        else {
            int val = pref[i] + 1;
            int next_p_sq = lower_bound(pref.begin(), pref.end(), val) - pref.begin();

            val = next_p_sq - i;
            while (i >= val) {
                permu[i] = next_p_sq - i;
                permu[next_p_sq - i] = i;
                i--;
            }
            i++;
        }
    }

    for (auto &&u: permu) cout << u << " "; cout << endl;
}

int main(void) {
    efficient();

    memset(p_sq, false, sizeof(p_sq));

    for (int i = 0; i < 2e5 + 5; i++) {
        if (isPerfectSquare(i))
            p_sq[i] = 1;
        if (i != 0) pref[i] = pref[i - 1] + p_sq[i];
    }

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