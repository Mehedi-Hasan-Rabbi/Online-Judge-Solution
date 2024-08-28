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

void July_36_2024()
{
    int n, m, k; cin >> n >> m >> k;
    int sz; cin >> sz;
    vector<ll> a(sz, 0), cnt;
    for (int i = 0; i < sz; i++)
        cin >> a[i];

    vector<vector<int>> mat(n, vector<int>(m, 0));
    
    for (int i = 0; i < k; i++) {
        if (i + k - 1 < m) 
            mat[0][i] = i + 1;
    }
    int l = 0, r = m - 1;
    while (l <= r) {
        if (mat[0][l] != 0)
            mat[0][r] = mat[0][l];
        else {
            mat[0][l] = mat[0][l - 1];
            mat[0][r] = mat[0][l - 1];
        }

        l++, r--;
    }

    for (int i = 0; i < k; i++) {
        if (i + k - 1 < n) {
            for (int j = 0; j < m; j++) {
                mat[i][j] = mat[0][j] * (i + 1);
                mat[n - 1 - i][j] = mat[0][j] * (i + 1);
            }  
        }
    }

    for (int i = 0; i < n; i++) {
        if (mat[i][0] == 0) {
            for (int j = 0; j < m; j++)
                mat[i][j] = mat[i - 1][j];
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cnt.push_back(mat[i][j]);
    
    sort(a.begin(), a.end(), greater<ll>());
    sort(cnt.begin(), cnt.end(), greater<ll>());

    ll ans = 0;
    for (int i = 0; i < sz; i++)
        ans += (a[i] * cnt[i]);

    cout << ans << endl;
}

int main(void) {
    efficient();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        // cout << "Case " << tc << ": ";
        July_36_2024();
    }

    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}