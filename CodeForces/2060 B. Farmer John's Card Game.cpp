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
    int n, m; cin >> n >> m;
    vector<vector<int>> cow(n, vector<int>(m, 0));

    for (int row = 0; row < n; row++)
        for (int col = 0; col < m; col++)
            cin >> cow[row][col];

    // Sort each row
    for (int row = 0; row < n; row++)
        sort(cow[row].begin(), cow[row].end());
    
    map<int, int> idx;
    for (int row = 0; row < n; row++) {
        idx[cow[row][0]] = row + 1;
    }

    vector<int> permutation;
    for (auto [key, val]: idx)
        permutation.push_back(val);
    
    // Sort rows based on the first element of each row
    sort(cow.begin(), cow.end(), [](const vector<int>& a, const vector<int>& b){
        return a[0] < b[0];
    });

    bool possible = true;
    int last = 0;
    for (int col = 0; col < m; col++) {
        if (cow[0][col] != last) {
            possible = false;
            break;
        }

        for (int row = 0; row < n - 1; row++) {
            if (cow[row][col] + 1 != cow[row + 1][col]) {
                possible = false;
                break;
            }

            last = cow[row + 1][col];
        }
        last++;

        if (possible == false) break;
    }

    if (possible) {
        for (auto u: permutation)
            cout << u << " ";
        cout << endl;
    }
    else cout << -1 << endl;
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