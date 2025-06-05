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
    string s; cin >> s;
    int n; cin >> n;
    vector<string> animal;
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        animal.push_back(str);
    }

    vector<int> vis(30, 0);
    for (auto u: animal) {
        vis[u[0] - 'a']++;
    }

    int sz = s.size();
    for (auto u: animal) {
        vis[u[0] - 'a']--;
        if (u[0] == s[sz - 1] and vis[u.back() - 'a'] == 0) {
            cout << u << "!" << endl;
            return;
        }
        vis[u[0] - 'a']++;
    }

    for (auto u: animal) {
        if (u[0] == s[sz - 1]) {
            cout << u << endl;
            return;
        }
    }

    cout << "?" << endl;
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