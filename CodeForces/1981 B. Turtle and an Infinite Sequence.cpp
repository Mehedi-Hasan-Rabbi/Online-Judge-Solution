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

// For m = 0; a(n) = n
// For m = 1; a(n) = n-1|n|n+1   (also, when m = 1, a(n-1) = n-2|n-1|n, a(n+1) = n|n+1|n+2)
// For m = 2; a(n) = a(n-1)|a(n)|a(n+1)
//                 = n-2|n-1|n|n-1|n|n+1|n|n+1|n+2
//                 = n-2|n-1|n|n+1|n+2
// So, if m = x then a(n) = n-x|...|n-2|n-1|n|n+1|n+2|...|n+x

void solve()
{
    int n, m; cin >> n >> m;

    int l = max(n - m, 0), r = n + m;
    ll ans = 0;

    // Check from l to r out of 32 bit which one is set
    for (int bit = 0; bit < 32; bit++) {
        // Check if l's ith bit is set or r's ith bit is set
        if ( (l & (1 << bit)) || (r & (1 << bit)) ) {
            ans = ans | (1 << bit);
            continue;
        }
        
        // If not then check which block are they from
        // if bit = 1; 010101010101
        // if bit = 2; 001100110011
        // if bit = 3; 000011110000
        // if bit = 4; 000000011111
        
        // Let's take bit = 4 --> |0000|1111|0000|1111| this is the bit sequence for 4th bit from l to r
        //              Block --> | 1  |  2 |  3 |  4 |
        // if block number is even then bit is not set, otherwise set
        int block_l = l / (1 << bit);
        int block_r = r / (1 << bit);

        if (block_l != block_r) {
            ans = ans | (1 << bit);
            continue;
        }
        else if (block_l == block_r and block_l % 2 == 1) {
            ans = ans | (1 << bit);
            continue;
        }
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