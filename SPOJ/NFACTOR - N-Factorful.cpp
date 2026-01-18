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
 
const int mx = 1e6 + 5;
int prime_divisors[mx]; // A factor is a divisor that divides evenly, leaving no remainder.
int commulative_prime[11][mx];
 
void harmonic_series () {
    // We will start from i = 2 because 1 is not a prime and 1 is a divisor to all. 
    for (int i = 2; i < mx; i++) {
 
        // If a a number is prime only then we will check.
        // And a prime number don't have any divisor with out 1 and itself
        // In this problem prime number has a divisor as itself.
        if (prime_divisors[i] != 0)
            continue;
 
        // So, now the loop will contribute only those numbers who has prime divisors.
        for (int j = i; j < mx; j += i) {
            prime_divisors[j] += 1;
        }
    }
}
 
void solve()
{
    int a, b, n; cin >> a >> b >> n;
 
    cout << commulative_prime[n][b] - commulative_prime[n][a - 1] << endl;
}
 
int main(void) {
    efficient();
 
    harmonic_series();
    for (int i = 1; i < mx; i++) {
        commulative_prime[ prime_divisors[i] ][i] = 1;
    }
 
    for (int i = 0; i <= 10; i++) {
        for (int j = 1; j < mx; j++) {
            commulative_prime[i][j] = commulative_prime[i][j - 1] + commulative_prime[i][j];
        }
    }
 
    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        solve();
    }
 
    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
} 