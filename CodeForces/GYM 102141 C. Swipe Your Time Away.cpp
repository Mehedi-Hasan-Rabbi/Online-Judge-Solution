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

int dx[] = {+1, -1, 0, 0, +1, +1, -1, -1};
int dy[] = {0, 0, -1, +1, +1, -1, +1, -1};

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

int n, m;

ll calc (vector<vector<int>> mat)
{
    vector<vector<pair<int, int>>> sum(n, vector<pair<int, int>>(m, {0, 0}));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1) sum[i][j].first = 1;
            else sum[i][j].first = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[j][i] == 1) sum[j][i].second = 1;
            else sum[j][i].second = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j > 0 and sum[i][j - 1].first != 0 and sum[i][j].first == 1)
                sum[i][j].first = sum[i][j - 1].first + sum[i][j].first;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0 and sum[j - 1][i].second != 0 and sum[j][i].second == 1)
                sum[j][i].second = sum[j - 1][i].second + sum[j][i].second;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (j > 0 and sum[i][j - 1].first != 0 and sum[i][j].first != 0)
                sum[i][j - 1].first = sum[i][j].first;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (j > 0 and sum[j - 1][i].second != 0 and sum[j][i].second != 0)
                sum[j - 1][i].second = sum[j][i].second;
        }
    }
    

    ll ans = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {

            if (sum[i][j - 1].first == sum[i][j].first and sum[i][j].first == sum[i][j + 1].first) {
                if (sum[i - 1][j].second == sum[i][j].second and sum[i][j].second == sum[i + 1][j].second) {
                    ll val = sum[i][j].first + sum[i][j].second - 1LL;
                    ans = max(ans, val);
                }
            }
        }
    }
    
    return ans;
}

void solve()
{
    cin >> n >> m;
    vector<vector<int>> game(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> game[i][j];


    vector<vector<int>> red(n, vector<int>(m, 0)),    // 1
                        green(n, vector<int>(m, 0)),  // 2
                        blue(n, vector<int>(m, 0)),   // 3
                        yellow(n, vector<int>(m, 0)), // 4
                        purple(n, vector<int>(m, 0)); // 5

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (game[i][j] == 1) red[i][j] = 1;
            if (game[i][j] == 2) green[i][j] = 1;
            if (game[i][j] == 3) blue[i][j] = 1;
            if (game[i][j] == 4) yellow[i][j] = 1;
            if (game[i][j] == 5) purple[i][j] = 1;
        }
    }

    ll sum = calc(red);
    sum = max(sum, calc(green));
    sum = max(sum, calc(blue));
    sum = max(sum, calc(yellow));
    sum = max(sum, calc(purple));

    if (sum == 1) sum = 0;

    cout << sum << endl;
}

int main(void)
{
    efficient();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cout << "Case " << tc << ": ";
        solve();
    }

    return 0;
}
