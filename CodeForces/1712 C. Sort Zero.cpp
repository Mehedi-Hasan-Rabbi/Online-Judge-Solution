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
    int n; cin >> n;
    vi a(n);

    set<int> st;
    map<int, int> indx;
    vi distinctPrefix;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        st.insert(a[i]);
        distinctPrefix.push_back(st.size());
        indx[a[i]] = i;
    }
    
    int check_start = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > a[i + 1]) {
            check_start = i;
            break;
        }
    }
    
    if (check_start == -1) { cout << 0 << endl; return; }
    
    int ans = 0, distinct = 0;
    for (int i = check_start; i >= 0; i--)
    {
        int last_id = indx[a[i]];
        distinct = max(distinct, distinctPrefix[last_id]);
        ans = max(ans, distinct);
    }
    
    cout << ans << endl;
}

int main(void)
{
    // efficient();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}
