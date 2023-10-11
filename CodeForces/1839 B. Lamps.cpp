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

bool cmp (pii a, pii b) {
    if (a.first != b.first)
        return a.first < b.first;
    else 
        return a.second > b.second;
}

void solve()
{
    ll n; cin >> n;
    vector<pair<ll, ll>> a;
    for (ll i = 0; i < n; i++)
    {
        ll x, y; cin >> x >> y;
        a.push_back({x, y});
    }
    sort(all(a), cmp);
    
    map<ll, ll> freq;
    ll ans = 0;
    ll x = 0;
    ll maxi = 0;

    for (auto &&i : a)
    {
        if (i.first > maxi) {
            ans += i.second;
            x++;
            maxi = max(maxi, x);
            freq[i.first]++;
            if (freq[maxi] > 0) {
                x -= freq[maxi];
                freq[maxi] = 0;
            }
        }
    }
    
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
