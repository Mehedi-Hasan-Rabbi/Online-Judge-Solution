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
    vector<vector<int>> monster;
    for (int cave = 0; cave < n; cave++) {
        int num; cin >> num;
        vector<int> mon(num, 0);
        for (int i = 0; i < num; i++) {
            cin >> mon[i];
        }
        monster.push_back(mon);
    }

    vector<pair<int, int>> pow;
    for (auto mon: monster) {
        int start = 0;
        for (int i = 0; i < (int) mon.size(); i++) {
            start = max(start, (mon[i] - i + 1));
        }
        pow.push_back({start, (int) mon.size()});
    }
    
    sort(pow.begin(), pow.end());
    int ans = pow[0].first, curr = pow[0].first + pow[0].second;
    for (int i = 1; i < n; i++) {
        if (curr < pow[i].first) {
            ans += pow[i].first - curr;
            curr += pow[i].first - curr;
        }
        curr += pow[i].second;
    }
    cout << ans << endl;
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