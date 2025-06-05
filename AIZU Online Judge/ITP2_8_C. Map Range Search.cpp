// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;
  
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
    map<string, ll> freq;
    for (int i = 1; i <= n; i++) {
        int type; cin >> type;

        if (type == 0) {
            string s; cin >> s;
            ll x; cin >> x;

            freq[s] = x;
        }
        else if (type == 1) {
            string s; cin >> s;

            if (freq.find(s) != freq.end())
                cout << freq[s] << endl;
            else
                cout << 0 << endl;
        }
        else if (type == 2) {
            string s; cin >> s;
            freq.erase(s);
        }
        else if (type == 3) {
            string l, r; cin >> l >> r;

            auto it = freq.lower_bound(l);

            while ( it != freq.end() and it->first <= r ) {
                cout << it->first << " " << it->second << endl;
                ++it;
            }
        }
    }
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