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

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    string s; cin >> s;
    int n = s.size();
    if (s[0] > '1' or n == 1) {
        cout << "NO" << endl;
        return;
    }

    string ff = "", ss = "";
    int carry = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        int num = s[i] - '0' + 10 - carry;
        int d = 5;
        for (d = 5; d <= 9; d++) {
            if ( log10(num - d) + 1 < 2 and (num - d) >= 5) {
                ff.push_back( d + '0' );
                ss.push_back( num - d + '0' );
                carry = 1;
                break;
            }
        }
        if (d == 10) {
            cout << "NO" << endl;
            return;
        }
    }
    
    reverse(ff.begin(), ff.end());
    reverse(ss.begin(), ss.end());

    cout << "YES" << endl;
    // cotu << ff << " " << ss << endl;
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