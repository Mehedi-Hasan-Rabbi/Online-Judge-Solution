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
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    // If k = n, then just check even indices in the array
    if (k == n) {
        int val = 1;
        for (int i = 2; i <= n; i += 2) {
            if (a[i] != val) {
                cout << val << endl;
                return;
            }
            val++;
        }
        cout << val << endl;
    }
    // If k != n, then - the answer will not exeed 2.
    /*
    Try to dry run in this two test cases;
    case 1: n = 6, k = 4, a = [1, 1, 1, 1, 2, 2]
    case 2: n = 6, k = 4, a = [1, 1, 2, 1, 2, 2]

    In, the array it confirm that 1st element will be in odd subarry and last element will be in even subarry.
    and read the official editorail carefully.
    */
   else {
        for (int i = 2; i <= n - k + 2; i++) {
            if (a[i] != 1) {
                cout << 1 << endl;
                return;
            }
        }
        cout << 2 << endl;
   }
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