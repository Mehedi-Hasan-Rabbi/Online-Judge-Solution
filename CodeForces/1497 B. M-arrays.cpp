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

void solve()
{
    int n, m; cin >> n >> m;
    map<int, int> freqOfMod;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        freqOfMod[x % m]++;
    }

    int ans = 0;
    
    for (auto &&[key, val] : freqOfMod)
    {
        if (key == 0 and val > 0) {++ans; val = 0;}
        else if (val > 0) {
            int x = key, y = m - x;
            if (freqOfMod[x] > 0 and freqOfMod[y] > 0){
                int mn = min (freqOfMod[x], freqOfMod[y]);

                if (freqOfMod[x] == freqOfMod[y]) {
                    freqOfMod[x] = 0, freqOfMod[y] = 0;
                }
                else if (freqOfMod[x] > freqOfMod[y]) {
                    freqOfMod[x] = freqOfMod[x] - mn - 1;
                    freqOfMod[y] = 0;
                }
                else {
                    freqOfMod[y] = freqOfMod[y] - mn - 1;
                    freqOfMod[x] = 0;
                }
                ++ans;
            }
        }
    }
    for (auto &&[key, val]: freqOfMod) {
        ans += val;
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