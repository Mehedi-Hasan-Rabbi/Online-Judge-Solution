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

void solve()
{
    ll a, b, r; cin >> a >> b >> r;
    vi binA(62, 0), binB(62, 0), binR(62, 0);

    if (b > a) swap(a, b);
    ll res = a - b;

    for (int i = 0; i < 62; i++) {
        if ( a & (1LL << i) )
            binA[i] = 1;
    }
    for (int i = 0; i < 62; i++) {
        if ( b & (1LL << i) )
            binB[i] = 1;
    }
    for (int i = 0; i < 62; i++) {
        if ( r & (1LL << i) )
            binR[i] = 1;
    }
    reverse(all(binA));
    reverse(all(binB));
    reverse(all(binR));
    
    ll x = 0LL;
    int pos = 0;
    for (int i = 0; i < 62; i++) {
        if (binR[i] == 1) {
            pos = i;
            break;
        }
    }
    
    for (int i = pos; i < 62; i++)
    {
        if (binA[i] == 1 and binB[i] == 0) {
            ll val = 1ll << (61 - i);
            if (x + val <= r) {
               x += val;
               if ( (b ^ x) > (a ^ x) ) { x -= val; continue; } 
               ll curr = (a ^ x) - (b ^ x);
               if (curr < res) res = curr;
               else x -= val;
            }
        }
        else if (binA[i] == 1 and binB[i] == 1) {
            ll val = 1ll << (61 - i);
            if (x + val <= r) {
               x += val;
               if ( (b ^ x) > (a ^ x) ) { x -= val; continue; } 
               ll curr = (a ^ x) - (b ^ x);
               if (curr < res) res= curr;
               else x -= val;
            }
        }
    }
    
    cout << res << endl;
}

int main(void)
{
    efficient();
    // clock_t z = clock();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve();
    }

    // cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC); // the run time printed here is in seconds
    return 0;
}
