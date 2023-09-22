// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define endl               '\n'
#define yes                cout << "YES" << endl
#define no                 cout << "NO" << endl
#define show(x)            cout << #x << " : " << x << endl
#define showtwo(x, y)      cout << #x << " : " << x << " " << #y << " : " << y << endl
#define all(a)             a.begin(),a.end()
#define pb                 push_back
#define pf                 push_front
#define mp                 make_pair
#define ff                 first
#define ss                 second
#define input_arr(vec)     for(auto &&it:vec) {cin >> it;}
#define display_arr(vec)   for (auto &&it : vec){cout << it << " ";} cout << endl;
#define files              freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient          ios_base::sync_with_stdio(0); cin.tie(0);

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    int n, k, x; cin >> n >> k >> x;
    ll sum = 0;
    vi ans;

    int mex = 0;
    while (mex != k)
    {
        ans.push_back(mex);
        mex++;
    }
    int mx = *max_element(all(ans));
    if (mx > x or ans.size() > n) {
        cout << -1 << endl;
        return;
    }

    if (k + 1 <= x) mex = x;
    else mex = k - 1;

    while (ans.size() != n)
        ans.push_back(mex);
    
    
    for (int i = 0; i < ans.size(); i++)
        sum += ans[i];
    
    cout << sum << endl;
}

int main(void)
{
    //efficient;

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        solve();
    }
    return 0;
}
