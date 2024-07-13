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
int h[mx], dp[mx], n, k;

int mini_cost(int it)
{
    if (it == n) return 0;
    if (dp[it] != -1) return dp[it];

    vector<int> cost;
    for (int i = 1; i <= k; i++) {
        if (it + i <= n) {
            int val = abs(h[it] - h[it + i]) + mini_cost(it + i);
            cost.push_back(val);
        }
    }
    dp[it] = *min_element(cost.begin(), cost.end());
    return dp[it];
}

int main(void) {
    efficient();

    memset(h, 0, sizeof(h));
    memset(dp, -1, sizeof(dp));
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    cout << mini_cost(1) << endl;

    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}