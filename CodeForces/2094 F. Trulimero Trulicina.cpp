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
 
void solve()
{
    int n, m, k; cin >> n >> m >> k;

    vector<vector<int>> grid(n, vector<int>(m, 0));

    if (m % k != 0) {
        int val = 1;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                grid[row][col] = val;
                val++;

                if (val > k) val = 1;
            }
        }
    }
    else {
        int val;
        for (int row = 0; row < n; row++) {
            if (row % 2 == 0) val = 1;
            else val = k;
            for (int col = 0; col < m; col++) {
                grid[row][col] = val;

                if (row % 2 == 0) {
                    val++;
                    if (val > k) val = 1;
                }
                else {
                    val--;
                    if (val == 0) val = k;
                }
            }

            if (k % 2 == 1 and row % 2 == 1) {
                int idx = k / 2;
                while (idx < m) {
                    swap(grid[row][idx], grid[row][idx + 1]);
                    idx += k;
                }
            } 
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
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