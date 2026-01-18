// In the name of Allah, the merciful.
#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#ifndef ONLINE_JUDGE
#include "algo/Debug.h"
#else
#define dbg(...)
#endif
 
typedef long long ll;
typedef unsigned long long ull;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // *X.find_by_order(n), X.order_of_key(n), *X.lower_bound(n), *X.upper_bound(n), X.erase(n)
// less<int> -> Ascending || greater<int> -> Descending || less_equal<int> -> Ascending Multiset || greater_equal<int> -> Descending Multiset
 
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

int n, k;
vector<int> a;

bool isPossible (int target) {
    // Find the last index which value < target
    int idx = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] < target) {
            idx = i;
            break;
        }
    }

    if (idx == -1) return true;     // All values is >= target

    // After that, do the addition operation
    for (int i = 0; i <= idx; i++) {
        int dist = idx - i;
        int add = max(0, k - dist);

        // After doing adding current value is not equal to target then impossible.
        if (a[i] + add < target) {
            return false;
        }
    }

    return true;
}

void solve()
{
    cin >> n >> k;
    a.resize(n, 0);
    int min_h = INT32_MAX, max_h = INT16_MIN;
    for (auto &u: a) {
        cin >> u;
        min_h = min(u, min_h);
        max_h = max(u, max_h);
    }

    int ans = min_h;

    // Binary Search
    int l = min_h, r = max_h + k;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (isPossible(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << ans << endl;
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