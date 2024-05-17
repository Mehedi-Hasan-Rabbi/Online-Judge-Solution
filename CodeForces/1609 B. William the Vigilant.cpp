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
    ll n, q; cin >> n >> q;
    string s; cin >> s;
    s = "#" + s;

    ll total = 0;
    for (int i = 3; i <= n; ) {
        string sub = s.substr(i-2, 3);
        if (sub == "abc") {
            i = i + 3;
            total++;
        } else i++;
    }

    string curr, new_;
    while (q--) {
        int i; char ch, prev;
        cin >> i >> ch;

        prev = s[i];
        if (i + 2 <= n) {
            curr = s.substr(i, 3);
            s[i] = ch;
            new_ = s.substr(i, 3);
            s[i] = prev;

            if (curr == "abc" and new_ != "abc") {
                total--; total = max(0LL, total);
            }
            else if (curr != "abc" and new_ == "abc") {
                total++; total = max(0LL, total);
            }
        }
        if (i - 2 >= 1) {
            curr = s.substr(i-2, 3);
            s[i] = ch;
            new_ = s.substr(i-2, 3);
            s[i] = prev;

            if (curr == "abc" and new_ != "abc") {
                total--; total = max(0LL, total);
            }
            else if (curr != "abc" and new_ == "abc") {
                total++; total = max(0LL, total);
            }
        }
        if (i + 1 <= n and i - 1 >= 1) {
            curr = s.substr(i-1, 3);
            s[i] = ch;
            new_ = s.substr(i-1, 3);
            s[i] = prev;

            if (curr == "abc" and new_ != "abc") {
                total--; total = max(0LL, total);
            }
            else if (curr != "abc" and new_ == "abc") {
                total++; total = max(0LL, total);
            }
        }

        s[i] = ch;
        cout << total << endl;
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