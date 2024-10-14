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

const int mx = 1e5 + 123;
int a[mx][4], dp[mx][4], n;

// Here, Day = Current day, last_activity = prev day activity through which I came to current day
int calc (int day, int last_activity) {
    if (day > n) return 0;
    if (dp[day][last_activity] != -1) return dp[day][last_activity];

    int cost = 0;
    for (int activity = 1; activity <= 3; activity++)
    {
        if (activity != last_activity) {
            int curr = a[day][activity] + calc(day + 1, activity);
            cost = max(cost, curr);
        }
    }

    return dp[day][last_activity] = cost;
}

int main(void) {
    efficient();
    memset(dp, -1, sizeof(dp));

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i][1] >> a[i][2] >> a[i][3];
    }

    cout << calc(1, 0) << endl;
    return 0;
}

// Iterative Approach
// const int mx = 1e5 + 123;
// ll dp1[mx], dp2[mx], dp3[mx];

// void solve()
// {
//     memset(dp1, -1, sizeof(dp1));
//     memset(dp2, -1, sizeof(dp2));
//     memset(dp3, -1, sizeof(dp3));

//     int n; cin >> n;
//     vector<ll> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);

//     for (int i = 1; i <= n; i++)
//         cin >> a[i] >> b[i] >> c[i];

//     dp1[n] = a[n], dp2[n] = b[n], dp3[n] = c[n];
//     for (int i = n - 1; i >= 1; i--)
//     {
//         // if select a[i]
//         ll max_hap1 = max(dp2[i + 1] + a[i], dp3[i + 1] + a[i]);
//         dp1[i] = max_hap1;

//         // if select b[i]
//         ll max_hap2 = max(dp1[i + 1] + b[i], dp3[i + 1] + b[i]);
//         dp2[i] = max_hap2;

//         // if select c[i]
//         ll max_hap3 = max(dp1[i + 1] + c[i], dp2[i + 1] + c[i]);
//         dp3[i] = max_hap3;
//     }   
//     cout << max({dp1[1], dp2[1], dp3[1]}) << endl;

// }