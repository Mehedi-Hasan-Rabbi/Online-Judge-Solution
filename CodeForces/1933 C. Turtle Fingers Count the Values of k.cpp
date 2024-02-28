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
// Another way to solve the problem is given below

void solve()
{
    int a, b, l; cin >> a >> b >> l;
    set<int> k;
    int ans = 0;

    if (a == 1 and b == 1) ans = 1;
    if (a == 1) {
        int val = 1;
        while (val <= l)
        {
            if (l % val == 0) k.insert(l / val);
            val = val * b;
        }
    }
    if (b == 1) {
        int val = 1;
        while (val <= l)
        {
            if (l % val == 0) k.insert(l / val);
            val = val * a;
        }
    }
    else {
        if (b > a) swap(a, b);
        
        int term_1 = 1;
        int term_2 = 1;
        while (term_1 <= l)
        {
            while (term_1 * term_2 <= l)
            {
                int term = term_1 * term_2;
                if (l % term == 0) k.insert(l / term);
                term_2 = term_2 * b;
            }
            term_1 = term_1 * a;
            term_2 = 1;
        }
    }
    
    ans = k.size();
    cout << ans << endl;
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


// Another way to solve the problem
// A to the power B using Binary Exponential O(log n)
// int binpow(int a, int b) {
//     int res = 1;
//     while (b > 0) {
//         if (b & 1) res = res * a;
//         a = a * a;
//         b >>= 1;
//     }
//     return res;
// }
 
// void solve()
// {
//     int a, b, l; cin >> a >> b >> l;
 
//     set<int> k;
//     int ans = 0;
//     if (a == 1 and b == 1) ans = 1;
//     if (a == 1) {
//         int y = 0;
//         int term = binpow(b, y);
//         while (term <= l)
//         {
//             if (l % term == 0) k.insert(l / term);
//             y++;
//             term = binpow(b, y);
//         }
//     }
//     if (b == 1) {
//         int x = 0;
//         int term = binpow(a, x);
//         while (term <= l)
//         {
//             if (l % term == 0) k.insert(l / term);
//             x++;
//             term = binpow(a, x);
//         }
//     }
//     else {
//         if (b > a) swap(a, b);
//         int x = 0, y = 0;
//         int term_1 = binpow(a, x);
//         int term_2 = binpow(b, y);
 
//         while (term_1 <= l)
//         {
//             while (term_1 * term_2 <= l)
//             {
//                 int term = term_1 * term_2;
//                 if (l % term == 0) k.insert(l / term);
//                 y++;
//                 term_2 = binpow(b, y);
//             }
//             y = 0; term_2 = binpow(b, y);
//             x++; term_1 = binpow(a, x);
//         }
//     }
    
//     ans = k.size();
//     cout << ans << endl;
// }