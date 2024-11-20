// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
#define endl               '\n'
#define efficient()        ios_base::sync_with_stdio(0); cin.tie(0); 
 
/*---------------------------------------------------------------------------------------------------------------*/
 
void solve()
{
    int n, total;
    cin >> n >> total;

    vector<int> coins(n, 0);
    for (auto &u: coins) cin >> u;

    vector<int> dp(total + 5, 1e9);

    // Base Case
    dp[0] = 0;

    for (int sum = 1; sum <= total; sum++) { // O(total)
        for (auto coin: coins) { // O(n)
            if (coin <= sum) {
                // Transition
                dp[sum] = min(dp[sum], dp[sum - coin] + 1);
            }
        }
    }
    
    cout << (dp[total] < 1e9 ? dp[total] : -1) << endl;
}
 
int main(void) {
    efficient();
 
    solve();
 
    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}