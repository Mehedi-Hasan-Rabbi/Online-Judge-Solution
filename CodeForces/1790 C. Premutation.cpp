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
    int n; cin >> n;
    vector<vector<int>> per;
    vi v(n-1), ans;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1; j++)
            cin >> v[j];
        per.push_back(v);
    }

    map<int, int> m;
    int x = per[0][0], y;
    for (int i = 0; i < n; i++)
    {
        m[per[i][0]]++;
        if (per[i][0] != x) y = per[i][0];
    }
    
    if (m[x] > m[y]) {
        ans.push_back(x);
        ans.push_back(y);
    }
    else {
        ans.push_back(y);
        ans.push_back(x);
    }
    
    for (int i = 1; i < n-1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (per[j][i] != ans[ans.size()-1]) {
                ans.push_back(per[j][i]);
                break;
            }
        }
    }
    display_arr(ans);
}

int main(void)
{
    //efficient;

    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
