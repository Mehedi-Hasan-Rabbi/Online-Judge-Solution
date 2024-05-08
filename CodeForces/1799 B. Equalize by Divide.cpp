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
    int n; cin >> n;
    vector<int> arr(n+1, 0);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    if (n == 1) {cout << 0 << endl; return;}

    vector<pair<int, int>> ans;
    int op;
    for (op = 0; op <= 30*n; op++)
    {
        // Maximum Element
        int ai = -1, i = -1;
        for (int ii = 1; ii <= n; ii++) {
            if (arr[ii] > ai) {
                ai = arr[ii];
                i = ii;
            }
        }
        // Second Maximum Element
        int aj = -1, j = -1;
        for (int ii = 1; ii <= n; ii++) {
            if (arr[ii] > aj and arr[ii] != ai) {
                aj = arr[ii];
                j = ii;
            }
        }
        
        if (j == -1) break;
        else {
            arr[i] = (ai / aj) + (ai % aj != 0);
            ans.push_back({i, j});
        }
    }

    sort(arr.begin()+1, arr.end());
    if (arr[1] == arr[n]) {
        cout << op << endl;
        for (auto &&u : ans)
            cout << u.first << " " << u.second << endl;
    }
    else cout << -1 << endl;
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