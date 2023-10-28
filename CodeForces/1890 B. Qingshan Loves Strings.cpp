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
#define yes                cout << "Yes" << endl
#define no                 cout << "No" << endl
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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    string t; cin >> t;

    int s_is_ok = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i+1]) {
            s_is_ok = 0;
            break;
        }
    }

    if (s_is_ok) {
        yes;
        return;
    }

    if (t[0] != t[m - 1]) {
        no;
        return;
    }

    int t_is_ok = 1;
    for (int i = 0; i < m - 1; i++)
    {
        if (t[i] == t[i+1]) {
            t_is_ok = 0;
            break;
        }
    }

    if (t_is_ok == 0) {
        no;
        return;
    }

    int ok = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1] and s[i] == t[0]) {
            ok = 0;
            break;
        } 
    }
    
    if (ok) yes;
    else no;
    
}

int main(void)
{
    efficient();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}
