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
 
const ll mod = 1e9 + 7;
const double PI = 3.14159265358979323846;
const double eps = 1e-9;
 
/*---------------------------------------------------------------------------------------------------------------*/
 
void solve()
{
	int n; cin >> n;
	vector<vector<int>> arr(n);
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		arr[i].resize(k);
		for (int j = 0; j < k; j++)
			cin >> arr[i][j];
	}

	// Sort 2D vector based on size
	sort(arr.begin(), arr.end(), [](vector<int>& a, vector<int>& b){
		return a.size() < b.size();
	});

	int max_k = arr.back().size();
	vector<int> ans(max_k, (int)1e9);

	vector<int> edit;
	edit.push_back(0);

	for (auto &v: arr) {
		int k = v.size();
		for (int e = 0; e < (int)edit.size(); e++) {
			int l = edit[e];
			int r = ((e + 1 < (int)edit.size()) ? edit[e + 1] : k);

			bool change = false;
			for (int i = l; i < r; i++) {
				if (ans[i] < v[i]) break;
				if (ans[i] > v[i]) { change = true; break; }
			}

			if (change) {
				for (int i = l; i < k; i++)
					ans[i] = v[i];
				
				while (edit.back() > l) edit.pop_back();
				edit.push_back(k);
				break;
			}
		}
	}

	for (auto &u: ans) cout << u << " ";
	cout << endl;
}
 
int main(void) {
	efficient();
 
	int t = 1;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		// cout << "Case " << tc << ": ";
		solve();
	}
 
	return 0;
}
