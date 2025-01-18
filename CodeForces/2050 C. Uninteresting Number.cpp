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
 
void solve()
{
    string s; cin >> s;
    sort(s.begin(), s.end());

    ll digit_sum = 0;
    for (auto u: s) {
        digit_sum += (u - '0');
    }

    if (digit_sum % 9 == 0) {
        cout << "YES" << endl;
        return;
    }

    vector<int> pref, suff;
    pref.push_back(0);
    suff.push_back(0);

    for (auto u: s) {
        if ( (u - '0') == 2) pref.push_back(2);
        else if ( (u - '0') == 3 ) pref.push_back(6);
    }

    for (int i = pref.size() - 1; i >= 1; i--)
        suff.push_back(pref[i]);

    for (int i = 1; i < pref.size(); i++)
        pref[i] = pref[i - 1] + pref[i];
    
    for (int i = 1; i < suff.size(); i++)
        suff[i] = suff[i - 1] + suff[i];
    

    ll need = (((digit_sum / 9LL) + 1) * 9) - digit_sum;
    int n = (int) pref.size();
    
    bool possible = false;
    while (need <= suff[n - 1]) {
        // First pref then suff
        ll val = need;
        int idx = upper_bound(pref.begin(), pref.end(), val) - pref.begin();
        val -= pref[idx - 1];
        if (val == 0) { possible = true; break; }

        idx = upper_bound(suff.begin(), suff.begin() + (n - idx), val) - suff.begin();
        val -= suff[idx - 1];
        if (val == 0) { possible = true; break; }

        // If not then, suff then pref
        val = need;

        idx = upper_bound(suff.begin(), suff.end(), val) - suff.begin();
        val -= suff[idx - 1];
        if (val == 0) { possible = true; break; }

        idx = upper_bound(pref.begin(), pref.begin() + (n - idx), val) - pref.begin();
        val -= pref[idx - 1];
        if (val == 0) { possible = true; break; }

        need = need + 9;
    }
    cout << (possible == true ? "YES" : "NO") << endl;
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