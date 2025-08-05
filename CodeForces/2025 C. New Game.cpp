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
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
    }

    k = min(k, (int) freq.size());

    int ans = -1;
    vector<int> num = {0}, count = {0};
    for (auto [key, val]: freq) {
        num.push_back(key);
        count.push_back(val);

        ans = max(ans, val);
    }

    if (k == 1) {
        cout << ans << endl;
        return;
    }

    n = (int) num.size();
    for (int i = 1; i < n; i++) count[i] += count[i - 1];

    int l = 1, r = 2, cnt = 1;
    while (r < n) {
        if (num[r - 1] + 1 != num[r]) {
            ans = max(ans, (count[r - 1] - count[l - 1]));
            l = r;
            cnt = 1;
        }
        else {
            cnt++;

            if (cnt < k)
                ans = max(ans, (count[r] - count[l - 1]));
            else {
                ans = max(ans, (count[r] - count[l - 1]));
                l++;
            }
        }
        r++;
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