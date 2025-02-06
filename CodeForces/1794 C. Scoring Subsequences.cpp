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
// Editorial is given below.
void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i;
        int idx = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (a[mid] >= (i - mid + 1)) {
                idx = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        int len = 1;
        if (idx != -1)
            len = i - idx + 1;
        
        ans.push_back(len);
    }

    for (auto u: ans) cout << u << " "; cout << endl;
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

/*
Editorial
------------
We know that if we divide x with y, then
if x >= y then Quotient (ভাগফল) is >= 1
else x < y then Quotient (ভাগফল) is < 1

Since the given array is a non-decreasing sequence. So, it is always better to take largest elements from the back side (suffix).
Now the question is how many elements we can take.

exp: arr -> 1 2 3 10; k = 4, then

if we take last 1 element then: 10 / 1 = 10
if we take last 2 element then: (10 * 3) / (1 * 2) = (10 / 1) * (3 / 2) = 15
if we take last 3 element then: (10 * 3 * 2) / (1 * 2 * 3) = (10 / 1) * (3 / 2) * (2 / 3) 10

if we see carefully then when we add 2nd element, it contributes (3 / 2) with the score, and (3 / 2) is >= 1
                    but when we add 3rd element, it contibutes (2 / 3) with the score, and (2 / 3) is < 1 which decrease the score

So, we need to find the last index from suffix which is greater then total number of element.
*/