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
    int n; cin >> n;
    vector<pair<int, int>> shoes, test;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        shoes.push_back({x, i + 1});
        m[i + 1] = i + 1;
    }

    if (n == 1) {
        cout << -1 << endl;
        return;
    }

    test = shoes;
    sort(all(test));

    for (int i = 0; i < n - 1; i++)
    {
        if (test[i].first == test[i+1].first) {
            m[i + 1] = test[i + 1].second;
            m[i + 2] = test[i].second;
            swap(test[i].second, test[i + 1].second);
        }
    }
    
    vi ans;
    for (auto &&i : m)
    {
        if (i.first == i.second) {
            cout << -1 << endl;
            return;
        }
        ans.push_back(i.second);
    }
    display_arr(ans);
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
