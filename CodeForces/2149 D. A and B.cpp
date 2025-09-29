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
    string s; cin >> s;
    s = "#" + s;
    
    vector<int> a, b;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == 'a') a.push_back(i);
        if (s[i] == 'b') b.push_back(i);
    }

    // Move only a
    ll move_a = 0;
    int mid = a.size() / 2;
    int l = mid - 1, r = mid + 1;

    while (true) {
        if (0 <= l) {
            move_a += abs(a[l] - a[l + 1]) - 1;
            a[l] = a[l + 1] - 1;
            l--;
        }
        if (r < a.size()) {
            move_a += abs(a[r - 1] - a[r]) - 1;
            a[r] = a[r - 1] + 1;
            r++;
        }
        
        if (l < 0 and r >= a.size())
            break;
    }

    // Move only b;
    ll move_b = 0;
    mid = b.size() / 2;
    l = mid - 1, r = mid + 1;

    while (true) {
        if (0 <= l) {
            move_b += abs(b[l] - b[l + 1]) - 1;
            b[l] = b[l + 1] - 1;
            l--;
        }
        if (r < b.size()) {
            move_b += abs(b[r - 1] - b[r]) - 1;
            b[r] = b[r - 1] + 1;
            r++;
        }
        
        if (l < 0 and r >= b.size())
            break;
    }

    cout << min(move_a, move_b) << endl;
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