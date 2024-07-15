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
    ull n; cin >> n;
    vector<int> bit(64, 0);
    vector<ull> ans;
    for (ull i = 0ull; i <= 63ull; i++) {
        if (n & (1ull << i))
            bit[i] = 1;
    }

    ans.push_back(n);
    ull l = 0;
    for (int i = 0; i <= 63; i++) {
        if (bit[i] == 1) {
            bit[i] = 0;

            ull val = n - (1ull << (ull) i);

            ans.push_back(val);
            l = (ull) i;
            break;
        }
    }

    ull limit = log2(n) + 1ull;
    while (l <= limit) {

        ull r = l + 1ull;
        while (r <= 63ull) {
            if (bit[r] == 1) break;
            r++;
        }

        if (l <= limit and r <= limit)
            swap(bit[l], bit[r]);
        else break;
        l = r;

        ull val = 0ull;
        for (ull ii = 0; ii <= 63; ii++) {
            if (bit[ii] == 1)
                val += (1ull << ii);
        }
        
        ans.push_back(val);
    }

    if (ans.back() == 0) ans.pop_back();
    
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto &&u: ans) cout << u << " "; cout << endl;
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