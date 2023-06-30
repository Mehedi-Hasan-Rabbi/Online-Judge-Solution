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
    ll n, ans = 0, cnt = 0, tot = 0; cin >> n;
    vi v;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if (x != 0) {
            v.push_back(x);
            ans += abs(x);
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < 0) {
            cnt++;
        }
        else {
            if (cnt > 0) tot++;
            cnt = 0;
        }
    }
    if (cnt > 0) tot++;
        
    cout << ans << " " << tot << endl;
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
