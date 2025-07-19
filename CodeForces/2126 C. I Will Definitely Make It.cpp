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
    int n, k; cin >> n >> k;
    vector<int> a(n + 1, 0), h;
    for (int i = 1; i <= n; i++) cin >> a[i];
    h = a;

    sort(h.begin(), h.end());
    auto ip = std::unique(h.begin(), h.end());
    h.resize(std::distance(h.begin(), ip));
    
    int water = 1;
    int idx = find(h.begin(), h.end(), a[k]) - h.begin();

    for (int i = idx; i + 1 < h.size(); ) {

        if ( abs(h[i + 1] - h[i]) <= abs(h[i] - water) + 1 ) {
            water += abs(h[i + 1] - h[i]);

            i++;
        }
        else {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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