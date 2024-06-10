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
    int n; cin >> n;
    vector<int> a(n, 0);
    set<int> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }

    if (st.size() == 1) cout << "NO" << endl;
    else if (st.size() > 2) {
        cout << "YES" << endl;
        cout << "B";
        for (int i = 1; i < n; i++)
            cout << "R";
        cout << endl;
    }
    else if (st.size() == 2) {
        cout << "YES" << endl;
        int ff = 0, sec = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == a[0]) ff++;
            else sec++;
        }
        if (ff > sec) {
            cout << "B";
            for (int i = 1; i < n; i++)
                cout << "R";
            cout << endl;
        }
        else if (ff < sec) {
            for (int i = 0; i < n - 1; i++)
                cout << "R";
            cout << "B";
            cout << endl;
        }
        else {
            int i = 0;
            for (i = 0; i < n - 1; i++) {
                if (a[i] == a[i+1])
                    cout << "B";
                else {
                    cout << "BB";
                    i++;
                    break;
                }
            }

            while (i < n - 1) {
                cout << "R";
                i++;
            }
            cout << endl;
        }
    }

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