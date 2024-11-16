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
bool isvalid(int x, int y) {
    return (x < n && x >= 0 && y < m && y >= 0);
}

void solve()
{
    cin >> n >> m;
    int arr[n][m];
    int zero = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 0)
                zero++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        for (int j = 0; j < m; j++)
        {
            cnt = 0;
            if (arr[i][j] == 1)
            {
                for (int k = 0; k < 8; k++)
                {
                    if (isvalid(i + dx[k], j + dy[k]))
                    {
                        if (arr[i + dx[k]][j + dy[k]] == 0)
                            cnt++;
                    }
                }
            }
            if (zero - cnt == 0)
            {
                cout << "WIN" << endl;
                return;
            }
        }
    }
    cout << "LOSE" << endl;
}

int main(void) {
    efficient();

    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }

    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}