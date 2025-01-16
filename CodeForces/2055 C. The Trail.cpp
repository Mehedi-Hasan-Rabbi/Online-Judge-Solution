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
const double PI = acos(-1);
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}
 
/*---------------------------------------------------------------------------------------------------------------*/
 
void solve()
{
    ll n, m; cin >> n >> m;
    string s; cin >> s;

    vector<vector<ll>> grid(n, vector<ll>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    vector<ll> row_sum, col_sum;

    // Calulating Each Row Sum
    for (int row = 0; row < n; row++) {
        ll sum = 0;
        for (int col = 0; col < m; col++) {
            sum += grid[row][col];
        }
        row_sum.push_back(sum);
    }

    // Calulating Each Column Sum
    for (int col = 0; col < m; col++) {
        ll sum = 0;
        for (int row = 0; row < n; row++) {
            sum += grid[row][col];
        }
        col_sum.push_back(sum);
    }

    int row = 0, col = 0;
    ll curr_sum = 0;

    for (auto u: s) {
        if (u == 'D') {
            curr_sum = (-1LL) * row_sum[row];
            grid[row][col] = curr_sum;

            row_sum[row] = row_sum[row] + curr_sum;
            col_sum[col] = col_sum[col] + curr_sum;

            row++;
        }
        else {
            curr_sum = (-1LL) * col_sum[col];
            grid[row][col] = curr_sum;
            
            row_sum[row] = row_sum[row] + curr_sum;
            col_sum[col] = col_sum[col] + curr_sum;
            
            col++;
        }
    }

    // One last step out. Can use row_sum/col_sum
    curr_sum = (-1LL) * row_sum[row];
    grid[row][col] = curr_sum;

    for (auto u: grid) {
        for (auto v: u)
            cout << v << " ";
        cout << endl;
    }
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