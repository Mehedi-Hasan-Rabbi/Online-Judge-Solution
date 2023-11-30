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
#define efficient()        ios_base::sync_with_stdio(0); cin.tie(0);
#define fraction()         cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return abs(a) * ( abs(b) / gcd ( a, b ) ); }

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    ll n; cin >> n;
    string s; cin >> s;

    ll sum = 0LL;
    for (int i = 0LL; i < n; i++)
    {
        if (s[i] == 'L') sum += (ll) i;
        else sum += (ll) (n - 1LL - i);
    }
    
    vector<pll> ans;
    ll temp = sum;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == 'L') {
            ll x = i, y = n - 1LL - i;
            if (y > x) {
                ans.push_back({y, x});
            }
        }
        else {
            ll x = n - 1LL - i, y = i;
            if (y > x) {
                ans.push_back({y, x});
            }
        }
    }
    
    if (ans.size() == 0) ans.push_back({0, 0});
    sort(all(ans), greater<pll>());
    while(ans.size() != n) ans.push_back({0, 0});

    for (auto &&u : ans)
    {
        sum -= u.second;
        sum += u.first;
        cout << sum << " ";
    }cout << endl;
    
}

int main(void)
{
    //efficient();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}
