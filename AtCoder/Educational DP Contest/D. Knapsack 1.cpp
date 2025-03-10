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
long long dp[123][mx];
int weight[123], value[123], n, bagSize;

long long knapsack (int idx, int currW)
{
    if (idx > n) return 0;
    if (dp[idx][currW] != -1) return dp[idx][currW];

    long long take = 0, no_take = 0;
    if (currW + weight[idx] <= bagSize) 
        take = value[idx] + knapsack(idx + 1, currW + weight[idx]);
    
    no_take = knapsack(idx + 1, currW);

    dp[idx][currW] = max(take, no_take);
    return dp[idx][currW];
}

int main(void) {
    efficient();

    cin >> n >> bagSize;
    for (int i = 1; i <= n; i++)
        cin >> weight[i] >> value[i];
    
    memset(dp, -1, sizeof(dp));

    cout << knapsack(1, 0) << endl;
    

    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}