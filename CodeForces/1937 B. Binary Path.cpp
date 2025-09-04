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
const double PI = 3.14159265358979323846;
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}
 
/*---------------------------------------------------------------------------------------------------------------*/
 
void solve()
{
    int n; cin >> n;
    string up; cin >> up;
    string down; cin >> down;

    string ans = ""; ans += up[0];
    int cnt = 0;
    bool cnt_end = false;
    for (int i = 1; i < n; i++) {
        if (up[i] == down[i - 1]) {
            ans += up[i];
            if (cnt_end == false) {
                if(cnt == 0) cnt += 2;
                else cnt++;
            }
        }
        else {
            if (cnt_end == false) {
                ans += min(up[i], down[i - 1]);
                if (up[i] < down[i - 1]) {
                    cnt = 1;
                }
                else cnt_end = true;
            }
            else {
                ans += down[i - 1];
            }
        }
    }
    ans += down[n - 1];
    cnt = max(1, cnt);
    cout << ans << endl;
    cout << cnt << endl;
}
 
int main(void) {
    // efficient();
 
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