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

long long dp[205][25][15], a[205];
int n, m, D;

long long solve (int idx, int currRem, int cnt)
{
    if (idx > n or cnt == m) {
        if (currRem == 0 and cnt == m) return 1;
        else return 0;

        // or, return (currRem == 0 and cnt == m);
    }
    if (dp[idx][currRem][cnt] != -1) return dp[idx][currRem][cnt];

    long long res = 0;
    int reminder = ((currRem % D)+ (a[idx] % D)) % D;
    if (reminder < 0) reminder += D; // IF, reminder is a negative number. Because, a[i] can be negative number;

    res += solve (idx + 1, reminder, cnt + 1);
    res += solve (idx + 1, currRem, cnt);

    return dp[idx][currRem][cnt] = res;
}

int main(void) {
    efficient();
    
    int q, tc = 1;
    while (cin >> n >> q) {
        if (n == 0 and q == 0) break;

        for (int i = 1; i <= n; i++) cin >> a[i];
        cout << "SET " << tc << ":" << endl;
        for (int i = 1; i <= q; i++) {
            cin >> D >> m;
            memset(dp, -1, sizeof(dp));

            cout << "QUERY " << i << ": " << solve(1, 0, 0) << endl;
        }
        tc++;
    }
    

    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}