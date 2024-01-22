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
// Editorial is given below
void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    
    long long ans = 0;
    int smallCount = 0;

    for (auto &&i : freq) {
        long long count = i.second;
        
        if (count >= 3)
            ans += ( count * (count - 1) * (count - 2) ) / 6;
        if (count >= 2)
            ans += ( ( count * (count - 1) ) / 2 ) * smallCount;
        
        smallCount += count;
    }
    
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


/*
Triangle Inequality Theorem.
----------------------------
In Euclidean geometry, a theorem that the sum of any two sides of a triangle is greater than or equal 
to the third side; in symbols, a + b ≥ c.
In cases where a + b = c, a degenerate triangle is formed. [Area = 0]

If the largest side is greater than the sum of the other two sides, it violates this inequality. The ends wouldn't reach each other.
Consider side lengths: 9, 4, and 3. The largest side is 9, which is greater than the sum of the other two sides (4 + 3 = 7). 
In this case, a triangle cannot be formed.

So, If a is the largest side then ---> a < b + c to form a non-degenerate triangle.

Solution
----------------------------
So, we khow than a < b + c; But, for this problem we are dealing with 2^ai;
So, for this problem a = b >= c; 
Checking for a = 5, b = 4, c = 4; --> 2^a = 32, 2^b = 16, 2^c = 16 --> 32 = 16 + 16 --> then the triangle will be degenerate.

So, now we have to calculate how many numbers are equal and how many combinations we can make with this number.

count = frequency of a number

if (count >= 3) --> then we have to choose 3 elements from the count. Means nC3.
or we can use binomial coefficient: ( count * (count - 1) * (count - 2) ) / 6
Here, count = number of ways we can take the first side;
      count - 1 = number of ways we can take the second side;
      count - 2 = number of ways we can take the third side;

      we, divide it by 6 because every side is taken 6 times;
      example of abc: abc, acb, cab, cba, bca, bac are all same.

if (count >= 2) --> then we have to choose 2 elements from the count. 
This means nC2 multiplied by the total number of small numbers that are below that frequency of a number
or, ( ( count * (count - 1) ) / 2 ) * smallCount;
Here, count = number of ways we can take the first side;
      count - 1 = number of ways we can take the second side;

      we, divide it by 2 because every side is taken 2 times;
      example of ab: ab, ba are all same.

      smallCount = total number of small numbers that are below that frequency of a number




If there is any wrong information then please forgive me and tell me through a message
*/