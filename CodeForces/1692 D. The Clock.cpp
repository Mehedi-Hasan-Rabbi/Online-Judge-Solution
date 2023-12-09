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
    string s; cin >> s;
    int n; cin >> n;

    s.erase(s.begin() + 2);
    int ans = 0;
    string temp = s; reverse(all(temp));
    if (temp == s) ans++;

    string hour_str = s.substr(0, 2);
    int hour = stoi( hour_str );

    string min_str = s.substr(2, 2);
    int min = stoi ( min_str );

    int add_h = n / 60;
    int add_m = n % 60;


    hour += add_h; min += add_m;
    if (min >= 60) {
        hour++;
        min = abs( 60 - min );
    }
    if (hour >= 24) {
        hour = abs( 24 - hour );
    }

    hour_str = to_string(hour);
    min_str = to_string(min);

    string curr;
    if (hour_str.size() == 1) curr = "0" + hour_str;
    else curr = hour_str;

    if (min_str.size() == 1) curr += "0" + min_str;
    else curr += min_str;

    map<string, int> freq;
    
    while (s != curr)
    {
        if (freq[curr] == 2) {
            break;
        }
        reverse(all(curr));
        string r_curr = curr;
        reverse(all(curr));
        freq[curr]++;

        if (curr == r_curr) ans++;

        hour_str = curr.substr(0, 2);
        hour = stoi( hour_str );

        min_str = curr.substr(2, 2);
        min = stoi ( min_str );

        hour += add_h; min += add_m;
        if (min >= 60) {
            hour++;
            min = abs( 60 - min );
        }
        if (hour >= 24) {
            hour = abs( 24 - hour );
        }

        hour_str = to_string(hour);
        min_str = to_string(min);
        
        if (hour_str.size() == 1) curr = "0" + hour_str;
        else curr = hour_str;

        if (min_str.size() == 1) curr += "0" + min_str;
        else curr += min_str;
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
        // cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}
