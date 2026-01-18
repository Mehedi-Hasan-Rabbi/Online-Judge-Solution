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

const int mx = 10000000 + 5;
bitset<mx> isPrime;
int ans[mx];

void sieve (int n) {
    for (int i = 3; i <= n; i += 2) {
        isPrime[i] = 1;
    }

    isPrime[2] = 1;
    int sq = sqrt(n) + 2; 

    for (int i = 3; i <= sq; i += 2) {
        if(isPrime[i]) {
            for (int j = i * i; j <= n; j += 2 * i) {
                isPrime[j] = 0;
            }
        }
    }
}

void solve()
{
    int n; cin >> n;
    cout << ans[n] << endl;
}
 
int main(void) {
    efficient();

    sieve (mx);
    for (int i = 1; i < mx; i++) {
        if (isPrime[i] == 0) continue;

        for (int j = 1; (j * j * j * j) * 1LL <= i; j++) {
            int val = j * j * j * j;
            int target = i - val;

            int sq = sqrt (target);
            while (sq * sq < target) sq++; // This will run 1 time. Worst-case 2 time

            if (sq * sq == target)
                ans[i] = 1;
        }

    }
    
    for (int i = 1; i < mx; i++)
        ans[i] = ans[i - 1] + ans[i];

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        solve();
    }
 
    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}