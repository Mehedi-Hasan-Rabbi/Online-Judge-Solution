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

int n, m;
const int mx = 200 + 10;
char c[mx][mx];
int levFire[mx][mx], levJane[mx][mx];
vector<pair<int, int>> multiSource;

void bfsFire ()
{
    queue<pair<int, int>> q;
    for (auto &&u: multiSource) {
        levFire[u.first][u.second] = 0;
        q.push(u);
    } 
    
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];

            if ( (1<=x1 and x1<=n) && (1<=y1 and y1<=m) and levFire[x1][y1] == -1 and c[x1][y1] != '#' ) {
                levFire[x1][y1] = levFire[x][y] + 1;
                q.push( {x1, y1} );
            }
        }
    }
}

void bfsJane (int x, int y)
{
    levJane[x][y] = 0;
    queue<pair<int, int>> q;
    q.push({x, y});

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];

            if ((1<=x1 and x1<=n) && (1<=y1 and y1<=m) and levJane[x1][y1] == -1 and (levJane[x][y]+1 < levFire[x1][y1])) {
                levJane[x1][y1] = levJane[x][y] + 1;
                q.push( {x1, y1} );
            }
        }
    }
    
}

void solve()
{
    memset(levFire, -1, sizeof(levFire));
    memset(levJane, -1, sizeof(levJane));
    multiSource.clear();
    
    int Jx, Jy;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];

            if (c[i][j] == 'F') multiSource.push_back( {i, j} );
            if (c[i][j] == 'J') Jx = i, Jy = j;
        }
    }

    bfsFire();
    bfsJane(Jx, Jy);

    int ans = INT32_MAX;
    for (int row = 1; row <= n; row++) {
        if (levJane[row][1] != -1) 
            ans = min(levJane[row][1], ans);
    }
    for (int row = 1; row <= n; row++) {
        if (levJane[row][m] != -1)
            ans = min(levJane[row][m], ans);
    }

    for (int col = 1; col <= m; col++) {
        if (levJane[1][col] != -1)
            ans = min(levJane[1][col], ans);
    }
    for (int col = 1; col <= m; col++) {
        if (levJane[n][col] != -1)
            ans = min(levJane[n][col], ans);
    }

    if (ans != INT32_MAX) cout << ans + 1 << endl;
    else cout << "IMPOSSIBLE" << endl;
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