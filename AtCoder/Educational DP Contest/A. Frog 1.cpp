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
int h[mx], dp[mx], n;

int mini_cost(int it)
{
    if (it == n) return 0;
    if (dp[it] != -1) return dp[it];

    int cost_1 = INT32_MAX, cost_2 = INT32_MAX;
    if (it + 1 <= n) cost_1 = abs(h[it] - h[it + 1]) + mini_cost(it + 1);
    if (it + 2 <= n) cost_2 = abs(h[it] - h[it + 2]) + mini_cost(it + 2);

    dp[it] = min(cost_1, cost_2);
    return dp[it];
}

int main(void) {
    efficient();

    memset(h, 0, sizeof(h));
    memset(dp, -1, sizeof(dp));
    
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    cout << mini_cost(1) << endl;

    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}


// Iterative Approach
// const int mx = 1e5 + 123;
// ll dp[mx];

// void solve()
// {
//     memset(dp, 0LL, sizeof(dp));

//     int n; cin >> n;
//     vector<ll> h(n + 1, 0);
//     for (int i = 1; i <= n; i++)
//         cin >> h[i];

//     dp[n] = 0;
//     for (int i = n - 1; i >= 1; i--) {

//         ll cost_1 = INT64_MAX, cost_2 = INT64_MAX;
//         if (i + 1 <= n) {
//             cost_1 = abs(h[i] - h[i + 1]) + dp[i + 1];
//         }
//         if (i + 2 <= n) {
//             cost_2 = abs(h[i] - h[i + 2]) + dp[i + 2];
//         }

//         dp[i] = min(cost_1, cost_2);
//     }

//     cout << dp[1] << endl;
// }