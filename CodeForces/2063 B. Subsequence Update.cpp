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
    int n, l, r; 
    cin >> n >> l >> r;

    vector<int> a(n, 0);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (l - 1 <= i and i <= r - 1)
            sum += a[i];
    }

    vector<int> rightSide, leftSide;
    for (int i = 0; i < r; i++)
        rightSide.push_back(a[i]);
    
    for (int i = n - 1; i >= l - 1; i--)
        leftSide.push_back(a[i]);
    
    sort(rightSide.begin(), rightSide.end());
    sort(leftSide.begin(), leftSide.end());

    ll right = 0, left = 0;
    for (int i = 0; i < r - l + 1; i++) {
        right += rightSide[i];
        left += leftSide[i];
    }

    ll ans = min(sum, min(right, left));

    cout << ans << endl;
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