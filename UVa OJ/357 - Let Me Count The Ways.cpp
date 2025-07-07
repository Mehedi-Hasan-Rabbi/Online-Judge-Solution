// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define endl               '\n'
#define efficient()        ios_base::sync_with_stdio(0); cin.tie(0);
/*---------------------------------------------------------------------------------------------------------------*/

const int mx = 30000 + 5;
int coin[] = {1, 5, 10, 25, 50};
ll dp[6][mx]; // [number of coins][maximun number input]

ll solve (int idx, int total)
{
    if (idx == 5 or total == 0) {
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

    int money;
    while (cin >> money) {
        ll ans = solve(0, money);

        if (ans == 1) cout << "There is only 1 way to produce " << money << " cents change." << endl;
        else cout << "There are " << ans << " ways to produce " << money << " cents change." << endl;
    }
 
    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}

/*
UVA 357 - Let Me Count The Ways
Problem Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=5&page=show_problem&problem=293
Vjudge Link: https://vjudge.net/problem/uva-357
*/