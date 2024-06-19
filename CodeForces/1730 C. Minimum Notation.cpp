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

void solve()
{
    string str; cin >> str;
    vector<pair<char, int>> s;
    for (int i = 0; i < str.size(); i++) 
        s.push_back( {str[i], i} );

    sort(s.begin(), s.end());

    int mx = s[0].second;
    vector<pair<char, int>> continuous, discontinuous;
    for (auto &&u: s) {
        if (u.second >= mx) {
            continuous.push_back(u);
            mx = max(mx, u.second);
        }
        else {
            discontinuous.push_back(u);
        }
    }

    priority_queue<char, vector<char>, greater<char>> ans;
    for (int i = 0; i < continuous.size(); i++) {
        ans.push(continuous[i].first);
    }
    for (int i = 0; i < discontinuous.size(); i++) {
        char ch = discontinuous[i].first + 1;
        ch = min(ch, '9');
        ans.push(ch);
    }

    while (!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }
    cout << endl;
}

int main(void) {
    // efficient();

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