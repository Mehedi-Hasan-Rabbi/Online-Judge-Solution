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

const int mx = 1e8 + 5;
bitset<mx> isPrime; //isPrime[i] = 1 means prime, isPrime[i] = 0 means composite/non-prime

// Time Complexity: O(n*log(log(n)))
// Space Complexity: O(n)
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

 
int main(void) {
    efficient();
 
    sieve(mx);

    int cnt = 0;
    for (int i = 1; i <= mx; i++) {
        if (isPrime[i] == 1) {
            cnt++;

            if (cnt % 100 == 1)
                cout << i << endl;
        }
    }
 
    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}