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

vector<ll> pow_of_3(30, 0);
vector<ll> price(30, 0);

void solve()
{
    ll n; cin >> n;

    ll ans = 0;    
    
    while (n >= 3) {
        int idx = lower_bound(pow_of_3.begin(), pow_of_3.begin() + 19, n) - pow_of_3.begin();
        if (pow_of_3[idx] > n) idx--;

        ll val = n / pow_of_3[idx];
        ans += price[idx] * val;

        n -= (val * pow_of_3[idx]);
    }

    ans += (n * 3LL);

    cout << ans << endl;
}
 
int main(void) {
    efficient();

    pow_of_3[0] = 1;
    for (ll i = 1; i < 20; i++) {
        pow_of_3[i] = pow_of_3[i - 1] * 3LL;
    }

    price[0] = 3;
    for (ll i = 1; i < 20; i++) {
        price[i] = pow_of_3[i + 1] + (i * pow_of_3[i - 1]);
    }
 
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