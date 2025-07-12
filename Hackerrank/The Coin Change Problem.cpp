// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define endl               '\n'
#define efficient()        ios_base::sync_with_stdio(0); cin.tie(0);
/*---------------------------------------------------------------------------------------------------------------*/

int n, m;
int coin[55];
ll dp[55][255]; // [number of coins][maximun number input]

ll solve (int idx, int total)
{
    if (idx == m or total == 0) {
        if (total == 0) return 1;
        else return 0;
        // return (total == 0); // In short 
    }
    if (dp[idx][total] != -1) return dp[idx][total];

    ll ans = 0;
    for (int i = 0; i <= total; i++) {
        if ( total - (i * coin[idx]) >= 0 )
            ans += solve (idx + 1, (total - (i * coin[idx])));
        else
            break;
    }

    return dp[idx][total] = ans;
}
 
int main(void) {
    efficient();
    
    memset(dp, -1, sizeof(dp));

    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> coin[i];

    cout << solve(0, n) << endl;
 
    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}

/*
The Coin Change Problem
Problem Link: https://www.hackerrank.com/challenges/coin-change/problem
*/
