/// In the name of Allah the merciful.
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
    vector<vector<char>> grid(n + 1, vector<char> (m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> grid[i][j];
    
    bool possible = false;
    // Checking Diagonal cornar character
    if (grid[1][1] == grid[n][m]) possible = true;
    else if (grid[1][m] == grid[n][1]) possible = true;

    // Checking First with Last Row
    for (int col = 2; col <= m - 1; col++)
    {
        if (grid[1][col] == grid[n][1] and grid[1][col] == grid[n][m])
            possible = true;
    }

    // Checking Last with First Row
    for (int col = 2; col <= m - 1; col++)
    {
        if (grid[n][col] == grid[1][1] and grid[n][col] == grid[1][m])
            possible = true;
    }

    // Checking First with Last Column
    for (int row = 2; row <= n - 1; row++)
    {
        if (grid[row][1] == grid[1][m] and grid[row][1] == grid[n][m])
            possible = true;
    }

    // Checking Last with First Column
    for (int row = 2; row <= n - 1; row++)
    {
        if (grid[row][m] == grid[1][1] and grid[row][m] == grid[n][1])
            possible = true;
    }


    if (possible) cout << "YES" << endl;
    else cout << "NO" << endl;
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