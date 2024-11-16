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

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}

/*---------------------------------------------------------------------------------------------------------------*/

const ll mx = (ll)1e8;
 
ll k;
 
ll possible(ll rad){
    ll cnt = 0;
    for(ll x = 0; x <= rad; x++){
        ll y = sqrt(rad * rad - x * x);
        cnt += y + 1;
    }
    ll ans = 4 * cnt - 4 * rad - 3;
  
    return ans;
}

void solve()
{
    cin >> k;
 
    ll L = 0, R = mx;
    ll ans = 0;
    while(L <= R){
        ll rad = (L + R) / 2;
 
        if(possible(rad) >= k){
            ans = rad;
            R = rad - 1;
        }
        else{
            L = rad + 1;
        }
        
    }
    cout << ans << '\n';
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