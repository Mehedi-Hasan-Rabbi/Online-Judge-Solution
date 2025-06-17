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
    vector<int> a(n + 1, 0), b(n + 1, 0);
    vector<bool> a_ok(n + 1, 0), b_ok(n + 1, 0);

    vector<pair<int, int>> ans;

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    // First full complete array a with value form 1 to n
    for (int i = n; i >= 1; i--) {
        int right_val = i, right_idx = i;

        // If found in array a
        int find_idx = find(a.begin(), a.end(), right_val) - a.begin();
        if (find_idx <= n) {
            int idx = find_idx;
            if (find_idx < right_idx) {
                while (idx < right_idx) {
                    swap(a[idx], a[idx + 1]);
                    ans.push_back({1, idx});
                    idx++;
                }
            }
            else if (find_idx > right_idx) {
                while (right_idx < idx) {
                    swap(a[idx - 1], a[idx]);
                    ans.push_back({1, idx - 1});
                    idx--;
                }
            }
        }
        // else found in array b
        else {
            find_idx = find(b.begin(), b.end(), right_val) - b.begin();
            int idx = find_idx;
            if (find_idx < right_idx) {
                while (idx < right_idx) {
                    swap(b[idx], b[idx + 1]);
                    ans.push_back({2, idx});
                    idx++;
                }
                
            }
            else if (find_idx > right_idx) {
                while (right_idx < idx) {
                    swap(b[idx - 1], b[idx]);
                    ans.push_back({2, idx - 1});
                    idx--;
                }
            }
            swap(a[right_idx], b[right_idx]);
            ans.push_back({3, right_idx});
        }
    }
    
    // Then complete array b with value n + 1 to 2 * n
    int right_val = 2 * n, right_idx = n;
    for (int i = n; i >= 1; i--) {
        int find_idx = find(b.begin(), b.end(), right_val) - b.begin();
        
        int idx = find_idx;
        if (find_idx < right_idx) {
            while (idx < right_idx) {
                swap(b[idx], b[idx + 1]);
                ans.push_back({2, idx});
                idx++;
            }
        }
        else if (find_idx > right_idx) {
            while (right_idx < idx) {
                swap(b[idx - 1], b[idx]);
                ans.push_back({2, idx - 1});
                idx--;
            }
        }
        
        right_idx--, right_val--;
    }

    cout << ans.size() << endl;
    for (auto u: ans) {
        cout << u.first << " " << u.second << endl;
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