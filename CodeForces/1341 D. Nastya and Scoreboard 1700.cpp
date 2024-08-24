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

const int mx = 2e3 + 123;
int dp[mx][mx], n, k;
string s[mx];
string digit[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

struct info {
    int nextIdx, costUntilNow, takenDigit;
    info(){}
    info(int nextIdx, int costUntilNow, int takenDigit): nextIdx(nextIdx), costUntilNow(costUntilNow), takenDigit(takenDigit) {}
}dir[mx][mx];

int convertCost (string x, string y)
{
    int opetarion = 0;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] == '1' and y[i] == '0') opetarion++;
        else if (x[i] == '0' and y[i] == '1') return - 1;
    }

    return opetarion;
}

int solve (int idx, int currCost)
{
    if (idx == n + 1) return (currCost == k);
    if (dp[idx][currCost] != -1) return dp[idx][currCost];

    int possible = 0;
    for (int i = 0; i < 10; i++) {
        int cost = convertCost(digit[i], s[idx]);
        if (cost == -1) continue;
        else if (currCost + cost <= k) {
            int val = solve (idx + 1, currCost + cost);

            if (val == 1) {
                possible = 1;
                dir[idx][currCost] = info{idx + 1, currCost+cost, i};
            }
        }
    }

    return dp[idx][currCost] = possible;
}

void print_dp (int idx, int cost)
{
    if (dir[idx][cost].takenDigit == -1) return;
    
    cout << dir[idx][cost].takenDigit;
    print_dp(dir[idx][cost].nextIdx, dir[idx][cost].costUntilNow);
}

int main(void) {
    efficient();

    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < mx; i++) {
        for (int j = 0; j < mx; j++)
            dir[i][j] = info(-1, -1, -1);
    }

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> s[i];
    
    if (solve(1, 0)) {
        print_dp(1, 0);
        cout << endl;
    }
    else cout << -1 << endl;
    
    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}
