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

const int mx = 2e5 + 123;
char s[5][mx];
bool vis[5][mx], pos = false;
int n;

bool dfs (int x, int y, int action)
{
    vis[x][y] = true;
    if (x == 2 and y == n) pos = pos | true;

    if (action == 1) {
        for (int i = 0; i < 4; i++) {
            int r = x + dx[i];
            int c = y + dy[i];

            if ( (1 <= r and r <= 2) && (1 <= c and c <= n) && !vis[r][c] && s[r][c] != '<' ) {
                dfs(r, c, 2);
            }
        }
    }
    else {
        if (s[x][y] == '>') {
            dfs(x, y + 1, 1);
        }
        else {
            dfs(x + 1, y, 1);
        }
    }

    return pos;
}

void solve()
{
    memset(vis, false, sizeof(vis));
    pos = false;

    cin >> n;
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= n; j++)
            cin >> s[i][j];
    }

    if (dfs(1, 1, 1)) cout << "YES" << endl;
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