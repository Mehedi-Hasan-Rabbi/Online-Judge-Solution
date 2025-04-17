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
    int a, b, k; cin >> a >> b >> k;
    map<int, int> girl;
    vector<pair<int, int>> couple(k);
    for (int i = 0; i < k; i++) {
        cin >> couple[i].first;
    }
    for (int i = 0; i < k; i++) {
        cin >> couple[i].second;
        girl[couple[i].second]++;
    }

    ll ans = 0, total = k;
    sort(couple.begin(), couple.end());

    vector<int> girl_idx;
    for (int i = 1; i < k; i++) {
        if (couple[i - 1].first == couple[i].first) 
            girl_idx.push_back(couple[i - 1].second);
        else {
            girl_idx.push_back(couple[i - 1].second);

            int cnt = girl_idx.size();
            for (auto u: girl_idx) {
                ll val = (total - cnt) - (girl[u] - 1);
                ans += val;
                girl[u]--, cnt--, total--;
            }
            girl_idx.clear();
        }
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