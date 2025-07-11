// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define endl               '\n'
#define efficient()        ios_base::sync_with_stdio(0); cin.tie(0);
/*---------------------------------------------------------------------------------------------------------------*/

const int mx = 10000 + 5;
int coin[21];
ll dp[23][mx]; // [number of coins][maximun number input]

ll solve (int idx, int total)
{
    if (idx == 21 or total == 0) {
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

    for (int i = 1; i <= 21; i++)
        coin[i - 1] = i * i * i;

    int money;
    while (cin >> money) {
        ll ans = solve(0, money);

        cout << ans << endl;
    }
 
    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}

/*
UVA 11137 - Ingenuous Cubrency
Problem Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2078
Vjudge Link: https://vjudge.net/problem/uva-11137
*/