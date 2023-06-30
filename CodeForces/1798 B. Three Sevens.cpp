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
    int days; cin >> days;
    vi ans;

    vector<vector<int>> parti;

    for (int i = 0; i < days; i++)
    {
        int n; cin >> n;
        vi v(n);       
        input_arr(v);
        sort(all(v));
        parti.push_back(v);
    }
    
    map<int, int> m;
    for (int i = days - 1; i >= 0; i--)
    {
        int flag = 0;
        for (int j = 0; j < parti[i].size(); j++)
        {
            if (flag == 0) {
                if (m[parti[i][j]] == 0) {
                    ans.push_back(parti[i][j]);
                    flag = 1;
                    m[parti[i][j]] = 1;
                }
            }
            else {
                m[parti[i][j]] = 1;
            }
        }
        
    }
    reverse(all(ans));
    if (ans.size() != days) {
        cout << -1 << endl;
        return;
    }
    display_arr(ans);
}

int main(void)
{
    efficient;

    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
