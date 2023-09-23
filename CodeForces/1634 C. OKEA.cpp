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
    int n, k; cin >> n >> k;
    int odd = 1, even = 2;

    vector<vector<int>> ans(n+1, vi (k+1));

    for (int i = 1; i < ans.size() - 1; i++)
    {
        for (int j = 1; j < ans[i].size(); j++)
        {
            if (i % 2 != 0) {
                ans[i][j] = odd;
                odd += 2;
            }
            else {
                ans[i][j] = even;
                even += 2;
            }
        }
    }
    
    for (int i = 1; i <= k; i++)
    {
        if (odd <= n*k) {
            ans[n][i] = odd;
            odd += 2;
        }
        else {
            ans[n][i] = even;
            even += 2;
        }
    }
    
    // Checking the last row
    int ok = 1;
    for (int i = 1; i <= k - 1; i++)
    {
        int sum = ans[n][i];
        int div = 2;
        for (int j = i + 1; j <= k; j++)
        {
            sum += ans[n][j];
            if (sum % div == 0) div++;
            else {
                ok = 0;
                break;
            }
        }
        if (ok == 0) {
            no;
            return;
        }
    }
    
    yes;
    for (int i = 1; i < ans.size(); i++)
    {
        for (int j = 1; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }cout << endl;
    }
}

int main(void)
{
    efficient;

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        solve();
    }
    return 0;
}
