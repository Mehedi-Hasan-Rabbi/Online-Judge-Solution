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
 
const ll mod = 1e9 + 7; // 1000000007;
const double PI = acos(-1);
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}
 
/*---------------------------------------------------------------------------------------------------------------*/
 
void solve() {
    int n; cin >> n;
    string s; cin >> s;

    if (count(s.begin(), s.end(), 'p') == 0) cout << "YES" << endl;
    else if (count(s.begin(), s.end(), 's') == 0) cout << "YES" << endl;
    else if (count(s.begin(), s.end(), '.') == n) cout << "YES" << endl;

    // One "s" and all are "p/." ['s' must be before 'p']
    else if (count(s.begin(), s.end(), 's') == 1 and s[0] == 's') {
        int p_cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'p') p_cnt++;

            else if (s[i] == 's') {
                if (p_cnt == 0) cout << "YES" << endl;
                else cout << "NO" << endl;
                break;
            }
        }
    }

    // One "p" and all are "s/." ['s' must be before 'p']
    else if (count(s.begin(), s.end(), 'p') == 1 and s[n - 1] == 'p') {
        int s_cnt = 0;
        for (int i = n - 1; i >= 0; i++) {
            if (s[i] == 's') s_cnt++;

            else if (s[i] == 'p') {
                if (s_cnt == 0) cout << "YES" << endl;
                else cout << "NO" << endl;
                break;
            }
        }
    }

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