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
    ll n, k, a, b; 
    cin >> n >> k >> a >> b;
    vll x(n+1), y(n+1);
    for (ll i = 1; i <= n; i++)
        cin >> x[i] >> y[i];

    ull ans = (ull) (abs(x[a] - x[b]) + abs(y[a] - y[b]));

    ull minA = ULLONG_MAX, minB = ULLONG_MAX;
    for (ll i = 1; i <= k; i++)
    {
        ull dis_major_to_a = (ull) (abs(x[a] - x[i]) + abs(y[a] - y[i]));
        ull dis_major_to_b = (ull) (abs(x[b] - x[i]) + abs(y[b] - y[i]));
        minA = min(minA, dis_major_to_a);
        minB = min(minB, dis_major_to_b);
    }
    
    ans = min(ans, minA+minB);
    cout << ans << endl;
}

int main(void)
{
    efficient();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        solve();
    }
    return 0;
}
