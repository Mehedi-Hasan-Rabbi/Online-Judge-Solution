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
    ll n, k; cin >> n >> k;

    vector<int> base_3;
    int min_deal = 0;

    // Base-3 Convertion
    while (n) {
        base_3.push_back(n % 3);
        min_deal += (n % 3);
        n = (n / 3);
    }
    // Example: n = 19, base_3 = {1, 0, 2} that means, 1*3^0 + 0*3^1 + 2*3^2 = 19;

    if (min_deal > k) {
        cout << -1 << endl;
        return;
    }

    k = k - min_deal; // Reamining extra deals
    /*
        Example: let's take n = 9, Then
            1 Deal of 3^2 which cost (1 Deal * 33) = 33 Coins
        But,3 Deal of 3^1 Which cost (3 Deal * 9) = 27 Coins

        So, 3 Deal of 3^x is more profitable than 1 Deal of 3^(x+1)
        
        Now, 
            Let's think of n = 9 then base_3 = {1,    0,    1}
            Each indes corresponding value   = {3^0   3^1   3^2}

            Now, if we can to reduce 3^2 to 3^1 then We need Extra 2 Deal and remove 1 Deal from 3^2
            Adding up we got 3 Deal. As we Explain avobe.
        
        So, If we divide k by 2 then we can say can we reduce 3^2 to 3^1
    */
    k = k / 2;

    // Try to "push" larger deals down into smaller deals if allowed.
    for (int i = (int) base_3.size() - 1; i >= 1; i--) {
        if (base_3[i] <= k) {
            // All 3^i can be converted to 3^(i-1)
            base_3[i - 1] += 3 * base_3[i];
            k -= base_3[i];
            base_3[i] = 0;
        }
        else {
            // Partially split, as much as k allows
            base_3[i - 1] += k * 3;
            base_3[i] -= k;
            break;
        }
    }

    ll ans = 0;
    for (int i = 0; i < (int) base_3.size(); i++) {
            ans += base_3[i] * price[i];
    }

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