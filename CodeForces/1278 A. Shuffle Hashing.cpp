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
    string h; cin >> h;

    vector<int> alpha_s(30, 0);
    for (int i = 0; i < (int) s.size(); i++) {
        alpha_s[s[i] - 'a']++;
    }
    
    vector<vector<int>> alpha_h(30, vector<int>((int) h.size() + 1, 0));
    for (int i = 0; i < (int) h.size(); i++) {
        alpha_h[h[i] - 'a'][i + 1] = 1;
    }
    for (int i = 0; i < 30; i++) {
        for (int j = 1; j <= (int) h.size(); j++) {
            alpha_h[i][j] = alpha_h[i][j - 1] + alpha_h[i][j];
        }
    }

    for (int i = 1; i <= (int) h.size(); i++) {
        for (int j = 1; j <= (int) h.size(); j++) {
            int possible = true;

            for (int ch = 0; ch < 26; ch++) {
                int val = alpha_h[ch][j] - alpha_h[ch][i - 1];
                if (val == alpha_s[ch]) continue;
                else {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
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