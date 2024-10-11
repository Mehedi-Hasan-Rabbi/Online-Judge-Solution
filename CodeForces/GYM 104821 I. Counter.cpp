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

void July_36_2024()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(m);
    for (auto &[ii, jj] : v)
    {
        cin >> ii >> jj;
    }
    v.push_back({0, 0});
    sort(v.begin(), v.end());
 
    int operation = 0, counter = 0;
    bool flag = true;
    for (int ii = 1; ii <= m; ii++)
    {
 
        int desired = v[ii].second - v[ii - 1].second - 1;
        int op_gap = v[ii].first - v[ii - 1].first - 1;
        if (v[ii].second!=0)
        {
            if(v[ii].second!=v[ii-1].second + op_gap + 1){
                if(v[ii].second>op_gap)
                    flag=false;
            }
        }
        
    }
    if (flag)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main(void) {
    efficient();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        // cout << "Case " << tc << ": ";
        July_36_2024();
    }

    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}