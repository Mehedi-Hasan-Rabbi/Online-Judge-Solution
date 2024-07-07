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
    int n, m; cin >> n >> m;
    vector<string> s;
    for (int i = 1; i <= n; i++) {
        string x; cin >> x;
        s.push_back(x);
    }

    int tot_one = 0, ans = 0, operation = INT32_MAX;
    for (auto &&u: s) {
        tot_one += count(u.begin(), u.end(), '1');
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            if (s[i].substr(j, 2) == "00" and s[i+1].substr(j, 2) == "00")
                operation = min(operation, 0);
            if ((s[i].substr(j, 2) == "10" and s[i+1].substr(j, 2) == "00") ||
                (s[i].substr(j, 2) == "01" and s[i+1].substr(j, 2) == "00") ||
                (s[i].substr(j, 2) == "00" and s[i+1].substr(j, 2) == "10") ||
                (s[i].substr(j, 2) == "00" and s[i+1].substr(j, 2) == "01"))
                operation = min(operation, 1);
            if ((s[i].substr(j, 2) == "11" and s[i+1].substr(j, 2) == "00") ||
                (s[i].substr(j, 2) == "00" and s[i+1].substr(j, 2) == "11") ||
                (s[i].substr(j, 2) == "10" and s[i+1].substr(j, 2) == "10") ||
                (s[i].substr(j, 2) == "01" and s[i+1].substr(j, 2) == "01"))
                operation = min(operation, 1);
            if ((s[i].substr(j, 2) == "01" and s[i+1].substr(j, 2) == "10") ||
                (s[i].substr(j, 2) == "10" and s[i+1].substr(j, 2) == "01"))
                operation = min(operation, 1);
            if ((s[i].substr(j, 2) == "10" and s[i+1].substr(j, 2) == "11") ||
                (s[i].substr(j, 2) == "01" and s[i+1].substr(j, 2) == "11") ||
                (s[i].substr(j, 2) == "11" and s[i+1].substr(j, 2) == "10") ||
                (s[i].substr(j, 2) == "11" and s[i+1].substr(j, 2) == "01"))
                operation = min(operation, 2);
            if (s[i].substr(j, 2) == "11" and s[i+1].substr(j, 2) == "11")
                operation = min(operation, 3);
        }
    }

    ans = tot_one - operation + (operation != 0);
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