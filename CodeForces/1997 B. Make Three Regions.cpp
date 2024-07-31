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

const int mx = 2e5 + 123;
char s[5][mx];
bool vis[5][mx];
int n;

void dfs(int x, int y)
{
    vis[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int r = x + dx[i];
        int c = y + dy[i];

        if ( (1 <= r and r <= 2) && (1 <= c and c <= n) && !vis[r][c] && vis[r][c] != 'x') {
            dfs(r, c);
        }
    }

    return;
}

void solve()
{
    memset(vis, false, sizeof(vis));

    int connected = 0;
    cin >> n;
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= n; j++)
            cin >> s[i][j];
    }
    
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= n; j++) {
            if (vis[i][j] == false and s[i][j] == '.') {
                connected++;
                dfs(i, j);
            }
        }
    }
    
    int ans = 0;
    if (connected == 1) {
        for (int i = 1; i <= n - 2; i++) {
            string row = "";
            row.push_back(s[1][i]);
            row.push_back(s[1][i + 1]);
            row.push_back(s[1][i + 2]);
            string col = "";
            col.push_back(s[2][i]);
            col.push_back(s[2][i + 1]);
            col.push_back(s[2][i + 2]);

            
            if ((row == "x.x") and (col == "...")) ans++;
            else if ((row == "...") and (col == "x.x")) ans++;
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