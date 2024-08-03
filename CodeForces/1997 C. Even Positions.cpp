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
    int n; cin >> n;
    string s; cin >> s;
    s = "#" + s;

    vector<int> left(n + 1, 0), right(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') left[i] = 1;
        else if (s[i] == ')') right[i] = 1;
    }

    for (int i = 1; i <= n; i++) right[i] = right[i - 1] + right[i];
    for (int i = 1; i <= n; i++) left[i] = left[i - 1] + left[i];

    ll ans = 0;
    int L = 0, R = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '_') {
            int idx1 = lower_bound(right.begin(), right.end(), R+1) - right.begin(); 
            int idx2 = lower_bound(left.begin(), left.end(), L+1) - left.begin();
            
            int dis1 = INT32_MAX, dis2 = INT32_MAX;
            if (i < idx1 and idx1 <= n) dis1 = idx1 - i;
            if (idx2 < i and idx2 <= n) dis2 = i - idx2;

            if (dis1 < dis2) {
                ans += dis1;
                R++;
            }
            else {
                ans += dis2;
                L++;
            }
        }
    }

    cout << ans << endl;
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