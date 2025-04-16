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
    string p; cin >> p;
    string s; cin >> s;
    int n = (int) p.size(), m = (int) s.size();

    vector<pair<char, int>> block_p, block_s;

    // Block for P
    char ch = p[0]; int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] == ch) {
            cnt++;
        }
        else {
            block_p.push_back({ch, cnt});
            ch = p[i];
            cnt = 1;
        }
    }
    block_p.push_back({ch, cnt});

    // Block for S
    ch = s[0], cnt = 0;
    for (int i = 0; i < m; i++) {
        if (s[i] == ch) {
            cnt++;
        }
        else {
            block_s.push_back({ch, cnt});
            ch = s[i];
            cnt = 1;
        }
    }
    block_s.push_back({ch, cnt});

    if (block_p.size() != block_s.size()) { cout << "NO" << endl; return; }

    for (int i = 0; i < (int) block_p.size(); i++) {
        if (block_p[i].first == block_s[i].first) {
            int size_p = block_p[i].second;
            int size_s = block_s[i].second;

            if (size_p <= size_s and size_s <= size_p * 2) continue;
            else {
                cout << "NO" << endl;
                return;
            }
        }
        else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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