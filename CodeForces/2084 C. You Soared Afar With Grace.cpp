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

    vector<int> idxA(n + 5, 0), idxB(n + 5, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        idxA[a[i]] = i;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        idxB[b[i]] = i;

        if (a[i] == b[i]) cnt++;
    }

    
    if (cnt >= 2 and n % 2 == 1) { cout << -1 << endl; return; }
    if (cnt >= 1 and n % 2 == 0) { cout << -1 << endl; return; }

    vector<pair<int, int>> ans;
    if (cnt == 1 and n % 2 == 1) {
        for (int i = 1; i <= n; i++) {
            if (a[i] == b[i] and i != (n / 2) + 1) {
                int l = i, r = (n / 2) + 1;

                if (l == r) continue;
                
                ans.push_back({l, r});
                
                swap(a[l], a[r]);
                swap(b[l], b[r]);
                
                idxA[a[l]] = l, idxA[a[r]] = r;
                idxB[b[l]] = l, idxB[b[r]] = r;
            }
        }
    }
    
    
    for (int i = 1; i <= (n / 2); i++) {
        int idx = idxB[a[i]];
        
        if (b[i] == a[idx]) {
            int l = idx, r = n - i + 1;

            if (l == r) continue;

            ans.push_back({l, r});
            
            swap(a[l], a[r]);
            swap(b[l], b[r]);
            
            idxA[a[l]] = l, idxA[a[r]] = r;
            idxB[b[l]] = l, idxB[b[r]] = r;
        }
        
        else { cout << -1 << endl; return; }
    }

    cout << ans.size() << endl;
    for (auto u: ans)
        cout << u.first << " " << u.second << endl;
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