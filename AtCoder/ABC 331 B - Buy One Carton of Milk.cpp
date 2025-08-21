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
 
const ll mod = 1e9 + 7; // 1000000007;
const double PI = 3.14159265358979323846;
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}
 
/*---------------------------------------------------------------------------------------------------------------*/

int n, s, m, l;
vector<pair<int, int>> price;
int dp[5][200];

int solve (int idx, int total) {
    if (idx == 3 or total <= 0) 
        return (total <= 0 ? 0 : INT32_MAX);
    if (dp[idx][total] != -1) return dp[idx][total];


    vector<int> money;
    for (int i = 0; i <= total ; i++) {

        if ( total - (price[idx].first * i) > 0 ){
            int val = solve (idx + 1, total - (price[idx].first * i));

            if (val != INT32_MAX)
                money.push_back(val + (price[idx].second * i));
        }
        else {
            int val = solve (idx + 1, total - (price[idx].first * i));

            if (val != INT32_MAX)
                money.push_back(val + (price[idx].second * i));
            
            break;
        }
    }

    return dp[idx][total] = *min_element(money.begin(), money.end());
}

void solve()
{
    memset(dp, -1, sizeof(dp));

    cin >> n >> s >> m >> l;
    price = { {6, s}, {8, m}, {12, l} };


    int ans = INT32_MAX;
    // Bruteforce Solution
    // for (int a = 0; a <= 100; a++) {
    //     for (int b = 0; b <= 100; b++) {
    //         for (int c = 0; c <= 100; c++) {
    //             if (a * 6 + b * 8 + c * 12 >= n) {
    //                 ans = min(ans, (a * s + b * m + c * l));
    //             }
    //         }
    //     }
    // }

    cout << solve(0, n) << endl;
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