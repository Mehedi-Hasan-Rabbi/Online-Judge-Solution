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
    vector<string> grid;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    for (int row = 0; row < n - 1; row++) {
        for (int col = 0; col < m - 1; col++) {
            if ((grid[row][col] == '.' or grid[row][col] == '*') and ((grid[row][col+1] == '.' or grid[row][col+1] == '*') )) {
                if ((grid[row+1][col] == '.' or grid[row][col] == '*') and ((grid[row+1][col+1] == '.' or grid[row][col+1] == '*') )) {
                    grid[row][col] = '*';
                    grid[row][col+1] = '*';
                    grid[row+1][col] = '*';
                    grid[row+1][col+1] = '*';
                }
            }
        }
    }

    for (auto &&u: grid) {
        for (int i = 0; i < m; i++) {
            if (u[i] == '.') {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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