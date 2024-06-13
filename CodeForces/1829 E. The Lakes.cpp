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

const int mx = 1e3 + 123;
int a[mx][mx];
bool vis[mx][mx];
int n, m;
ll ans = 0, curr = 0;

void dfs (int x, int y)
{
    vis[x][y] = true;
    curr += a[x][y];

    for (int i = 0; i < 4; i++) {
        int r = x + dx[i];
        int c = y + dy[i];

        if ( (1 <= r and r <= n) && (1 <= c and c <= m) && !vis[r][c] && a[r][c] != 0)
            dfs(r, c);
    }
}

void solve()
{
    memset(vis, false, sizeof(vis));
    ans = 0, curr = 0;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (vis[i][j] == false and a[i][j] != 0) {
                dfs(i, j);
                ans = max(ans, curr);
                curr = 0;
            }
        }
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