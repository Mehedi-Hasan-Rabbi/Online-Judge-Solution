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
 
const ll mod = 1e9 + 7; // 1000000007;
const double PI = 3.14159265358979323846;
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}
 
/*---------------------------------------------------------------------------------------------------------------*/
 
bool seive [1010000];
vector<int> prime;
void seiveGen (int limit) {
	limit += 100;
	int sqrtn = sqrt(limit);
	for(int i= 3; i <= sqrtn; i += 2) {
		if(!seive[i>>1]) {
			for(int j = i*i; j < limit; j += i + i) {
				seive[j>>1] = 1;
			}
		}
	}
	prime.push_back(2);
	for(int i = 3; i < limit; i += 2) {
		if(!seive[i>>1]) prime.push_back(i);
	}
}

void solve()
{
    int l, r; cin >> l >> r;
    int ans = -1;

    for (int i = 0; i < (int) prime.size(); i++) {
        if ( l <= prime[i] and prime[i] <= r) {
            ans = max(prime[i], ans);
        }
    }

    cout << ans << endl;
}
 
int main(void) {
    efficient();
    
    seiveGen(10000);

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