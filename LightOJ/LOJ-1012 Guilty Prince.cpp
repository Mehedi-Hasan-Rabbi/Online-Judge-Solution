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

int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, -1, +1};

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}

/*---------------------------------------------------------------------------------------------------------------*/

const int mx = 30;
bool vis[mx][mx];
char c[mx][mx];

int cnt = 0, n, m;
void dfs (int x, int y)
{
    vis[x][y] = true;
    cnt++;

    for (int i = 0; i < 4; i++) {
        int x1 = x + dx[i];
        int y1 = y + dy[i];

        if ( (1 <= x1 and x1 <= n) and (1 <= y1 and y1 <= m) and !vis[x1][y1] and c[x1][y1] != '#' )
            dfs(x1, y1);
    }

}

void solve()
{
    // Clear all the previous data
    memset(vis, false, sizeof(vis));
    cnt = 0;

    cin >> m >> n;
    int row = 0, col = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++){
            cin >> c[i][j];

            if (c[i][j] == '@') {
                row = i, col = j;
            }
        }
    }

    dfs(row, col);
    cout << cnt << endl;
}

int main(void) {
    efficient();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cout << "Case " << tc << ": ";
        solve();
    }

    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}
