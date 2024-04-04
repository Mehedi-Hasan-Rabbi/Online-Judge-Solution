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
#define all(a)             (a).begin(),(a).end()
#define rall(a)            (a).rbegin(),(a).rend()
#define toLowerCase(s)     transform(s.begin(), s.end(), s.begin(), ::tolower);
#define toUpperCase(s)     transform(s.begin(), s.end(), s.begin(), ::toupper);
#define pb                 push_back
#define pf                 push_front
#define mp                 make_pair
#define ff                 first
#define ss                 second
#define mem(a, b)          memset(a, b, sizeof(a) )
#define input_arr(vec)     for(auto &&it:vec) {cin >> it;}
#define display_arr(vec)   for (auto &&it : vec){cout << it << " ";} cout << endl;
#define files()            freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient()        ios_base::sync_with_stdio(0); cin.tie(0);
#define fraction()         cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return abs(a) * ( abs(b) / gcd ( a, b ) ); }

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}

template < typename F, typename S >ostream& operator << ( ostream& os, const pair< F, S > & p ) {return os << "(" << p.first << ", " << p.second << ")";}
template < typename T >ostream &operator << ( ostream & os, const vector< T > &v ) {os << "{";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << *it;}return os << "}";}
template < typename T >ostream &operator << ( ostream & os, const set< T > &v ) {os << "[";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << *it;}return os << "]";}
template < typename T >ostream &operator << ( ostream & os, const multiset< T > &v ) {os << "[";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << *it;}return os << "]";}
template < typename F, typename S >ostream &operator << ( ostream & os, const map< F, S > &v ) {os << "[";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << it -> first << " = " << it -> second ;}return os << "]";}
 
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
 
void faltu () {cerr << endl;}
template <typename T>void faltu( T a[], int n ) {for(int i = 0; i < n; ++i) cerr << a[i] << ' ';cerr << endl;}
template <typename T, typename ... hello>void faltu( T arg, const hello &... rest) {cerr << arg << ' ';faltu(rest...);}

/*---------------------------------------------------------------------------------------------------------------*/

long long dp[100123];
long long latter[30][100123];

long long fact (long long x)
{
    if (x == 0) return 1ll;
    if (dp[x] != 0) return dp[x];
    
    long long res = ((x % MOD) * (fact(x - 1) % MOD)) % MOD;
    dp[x] = res;
    return dp[x];
}

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int n, m; cin >> n >> m;
    string s; cin >> s;
    s = '#' + s;

    for (int i = 1; i <= n; i++) {
        int ch = s[i] - 'a' + 1;
        latter[ch][i] = 1;
    }

    for (int ch = 1; ch <= 26; ch++) {
        for (int i = 1; i <= 100100; i++) {
            latter[ch][i] = latter[ch][i - 1] + latter[ch][i];
        } 
    }

    while (m--) {
        int l, r; cin >> l >> r;
        ll ans = dp[r - l + 1];
        
        ll div = 1;
        for (int ch = 1; ch <= 26; ch++) {
            int cnt = (latter[ch][r] - latter[ch][l - 1ll]);
            div = dp[cnt];

            div = binpow(div, (MOD - 2));
            
            if (div > 0)
                ans = ((ans % MOD) * (div % MOD)) % MOD;
        }

        ans--;
        if (ans < 0) ans = 0;
        cout << ans << endl;
    }
    
}

int main(void)
{
    efficient();
    // clock_t z = clock();

    for (int i = 1; i <= 100100; i++) {
        fact(i);
    }

    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve();
    }

    // cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC); // the run time printed here is in seconds
    return 0;

    // Every problem has its weakness. 
    // This problem's weakness is...the existence of me!
}