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
    ll a, b; cin >> a >> b;

    if (a % 2 == 1 and b % 2 == 1) {
        cout <<  (a * b) + 1 << endl;
        return;
    }
    else if (a % 2 == 0 and b % 2 == 1) {
        cout << -1 << endl;
        return;
    }
    else if (b % 2 == 0) {
        if ((b / 2) % 2 == 1 and a % 2 == 1)
            cout << -1 << endl;
        else
            cout << ((a * b) / 2) + 2 << endl;
        return;
    }
}

/* 
    To, maximize (a * k + (b / k)), k have to be maximum. That is for sure.
        - From the question b is divisible by k
    
    There are 4 possibilities:  a -> odd, b --> odd
                                a --> even, b --> odd
                                a --> odd, b --> even
                                a --> even, b --> even

    Case 1: Since we need to maximize k. Then, maximum k that can divide b is k itself.
            So, if, k = b Then, (a * b) + (b / b)
                                (a * b) + 1
            Now,
                1 is odd. Then to make (a * b) + 1 even, (a * b) must be odd.
                And, to make (a * b) both a, b need to be odd.

            So, if a and b both are odd then answer is (a * b) + 1;
    
    Case 2: If b --> even. Then the next highest divisor of b will be k = (b/2).
            Then, (a * b/2) + (b/(b/2)) => (a * b/2) + 2
            Now,
                2 is even. Then to make (a * b) + 1 even, (a * b/2) must be even.
            So, in which condition (a * b/2) will be even?

            Since we already know b is even,
                1) If (b / 2) --> odd and a --> odd
                    Then multiplication of two odd is always odd.
                    So, answer will be -1.
                2) If (b / 2) --> even
                    Then, begin a even or odd doesn't matter.
                    Because, even * odd = even
                             even * even = even
                    So, the answer will be (a * b/2) + 2
    
    Case 3: If a --> even and b --> odd.
            Since, b is odd. Then all the divisor k of b must be odd.
            Then, b/k = odd. [Paired Divisor]
            and, a * k = even [even * odd]

            So, (a * k) + (b / k) => even + odd ==> odd
            So, the final answer is -1.
*/
 
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