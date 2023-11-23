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

int main(void)
{
    //efficient();

    ll n, q; cin >> n >> q;
    vll a(n); input_arr(a);
    map<int, ll> curr_val;

    for (int i = 0; i < n; i++) curr_val[i] = a[i];
    ll ans = accumulate(all(a), 0LL);
    ll new_val = -1;

    while (q--)
    {
        int type; cin >> type;
        if (type == 1) {
            ll idx, val; cin >> idx >> val;
            idx--;
            if (curr_val[idx] == 0) curr_val[idx] = new_val;
            ans -= curr_val[idx];
            ans += val;
            curr_val[idx] = val;
        }
        else {
            ll val; cin >> val;
            curr_val.clear();
            ans = val * n;
            new_val = val;
        }
        cout << ans << endl;
    }
    
    return 0;
}
