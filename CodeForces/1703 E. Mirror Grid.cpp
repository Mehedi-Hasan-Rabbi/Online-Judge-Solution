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
    int n; cin >> n;
    vector<vector<char>> grid(n+1, vector<char>(n + 1, '#'));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n ; j++)
            cin >> grid[i][j];
    }

    int ans = 0;
    int x[] = {-1, 1, 1, n, n}; // 1 base index
    int y[] = {-1, 1, n, n, 1};
    int cnt = n - 1;
    for (int lmt = 1; lmt <= ((n/2) + (n%2==1)); lmt++) 
    {
        int x1 = x[1], y1 = y[1], x2 = x[2], y2 = y[2], x3 = x[3], y3 = y[3], x4 = x[4], y4 = y[4];
        for (int ii = 1; ii <= cnt; ii++)
        {
            int one = 0, zero = 0;
            if (grid[x1][y1] == '0') zero++; else one++; grid[x1][y1] = '*';
            if (grid[x2][y2] == '0') zero++; else one++; grid[x2][y2] = '*';
            if (grid[x3][y3] == '0') zero++; else one++; grid[x3][y3] = '*';
            if (grid[x4][y4] == '0') zero++; else one++; grid[x4][y4] = '*';

            ans += min(zero, one);
            x1++; y2--; x3--; y4++;
        }
        cnt = cnt - 2;
        x[1]++, y[1]++, x[2]++, y[2]--, x[3]--, y[3]--, x[4]--, y[4]++;
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