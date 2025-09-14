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
    string s, temp; cin >> s;
    temp = s;

    sort(temp.begin(), temp.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' and temp[i] == '1')
            ans++;
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

/*
Other Solution
--------------
void solve()
{
    int n; cin >> n;
    string s, temp; cin >> s;
    temp = s;
    int ans1 = 0, ans2 = 0;
 
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            int j = -1, k = -1;
            for (int id = n - 1; id > i; id--) {
                if (s[id] == '0') { k = id; break; }
            }
 
            if (k != -1) {
                for (int id = k - 1; id > i; id--) {
                    if (s[id] == '0') { j = id; break; }
                }
            }
 
            if (j != -1 and k != -1) {
                swap(s[i], s[k]);
                ans1++;
            }
            else if (k != -1) {
                swap(s[i], s[k]);
 
                if (i > 0) ans1 += 1;
                else ans1 += 2;
            }
        }
    }
    
    s = temp;
    
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            int j = -1, k = -1;
            for (int id = 0; id < i; id++) {
                if (s[id] == '1') { k = id; break; }
            }
 
            if (k != -1) {
                for (int id = k + 1; id < i; id++) {
                    if (s[id] == '1') { j = id; break; }
                }
            }
 
            if (j != -1 and k != -1) {
                swap(s[i], s[k]);
                ans2++;
            }
            else if (k != -1) {
                swap(s[i], s[k]);
 
                if (i < n - 1) ans2 += 1;
                else ans2 += 2;
            }
        }
    }
 
    cout << min(ans1, ans2) << endl;
}

*/