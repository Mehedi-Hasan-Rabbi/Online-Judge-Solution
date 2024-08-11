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

bool seive [1010000];
vector<int> prime;
void seiveGen (int limit) {
    if (limit <= 1) return;
    
	int sqrtn = sqrt(limit + 1);
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

const int mx = 1200;
long long dp[260][mx][15];
int n, k;

long long solve (int idx, int currSum, int cnt)
{
	if (idx == prime.size() or currSum >= n or cnt == k) {
		if (currSum == n and cnt == k) return 1;
		else return 0;

		// or, return (currSum == n and cnt == k);
	}
	if (dp[idx][currSum][cnt] != -1) return dp[idx][currSum][cnt];

	long long res = 0;
	res += solve(idx + 1, currSum+prime[idx], cnt + 1);
	res += solve(idx + 1, currSum, cnt);

	return dp[idx][currSum][cnt] = res;
}

int main(void) {
    efficient();

    seiveGen(1200);
	
	while (cin >> n >> k) {
		if (n == 0 and k == 0) break;

		memset(dp, -1, sizeof(dp));
		cout << solve(0, 0, 0) << endl;
	}

    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}