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

const int mx = 1e5 + 123;
ll n, bagSize, weight[123], value[123];
ll dp[123][mx];

ll knapsack (int idx, int value_left)
{
    if (value_left == 0) return 0;
    if (idx > n) return 1e15;
    if (dp[idx][value_left] != -1) return dp[idx][value_left];

    // We can always allowed to not picking an item. But, if we want want to pick an item we need a condition.
    ll pick, no_pick, ans; // We can't assign any value to any of these variable
    // Not picking an item
    no_pick = knapsack(idx + 1, value_left);
    ans = no_pick;

    // Picking an item
    if (value_left - value[idx] >= 0) {
        pick = weight[idx] + knapsack(idx + 1, value_left - value[idx]);
        ans = min(no_pick, pick);
    }

    return dp[idx][value_left] = ans;
}

void solve()
{
    cin >> n >> bagSize;
    for (int i = 1; i <= n; i++)
        cin >> weight[i] >> value[i];
    
    memset(dp, -1, sizeof(dp));

    // How much weight do I need to carry currValue
    for (int currValue = 1e5 + 5; currValue >= 0; currValue--) {
        ll weight_need = knapsack(1, currValue);
        if (weight_need <= bagSize) {
            cout << currValue << endl;
            break;
        }
    }
}

int main(void) {
    efficient();

    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }

    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}