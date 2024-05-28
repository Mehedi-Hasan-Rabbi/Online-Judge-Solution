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
    int x; cin >> x;
    vector<int> bit(35, 0);

    for (int i = 0; i < 32; i++) {
        if ( x & (1 << i) )
            bit[i] = 1;
    }
    
    
    // Solution if consecutive 1's found then, 011111 = 10000-1 (for this problem)
    int start = INT32_MAX, end = INT32_MIN;
    for (int i = 0; i < 33; i++) {
        if (bit[i] == 1 and bit[i + 1] == 1) {
            start = min(i, start);
            end = max(i, end);
        }
        else {
            end = max(i, end);
            if (start != INT32_MAX and end != INT32_MIN) {
                bit[start] = -1; start++;
                bit[end + 1] = 1;
                while (start <= end) {
                    bit[start] = 0;
                    start++;
                }
            }
            start = INT32_MAX, end = INT32_MIN;
        }
    }
    
    cout << 32 << endl;
    for (int i = 0; i < 32; i++)
        cout << bit[i] << " ";
    cout << endl;
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