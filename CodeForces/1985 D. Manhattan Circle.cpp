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

    int col = -1, row = -1;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;

        if (col == -1 and row == -1) {
            for (int j = 0; j < m; j++) {
                if (s[j] == '#') {
                    row = i;
                    col = j;
                }
            }
        }

        grid.push_back(s);
    }

    int cnt = 0;
    for (int i = row; i < n; i++) {
        if (grid[i][col] == '#') cnt++;
        else break;
    }

    if (cnt > 2) row = row + (cnt / 2) + 1;
    else row++;
    col++;

    cout << row << " " << col << endl;
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