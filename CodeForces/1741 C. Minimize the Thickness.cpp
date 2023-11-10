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
    vi a(n); input_arr(a);

    int ans = n;
    int segSum = 0;

    for (int i = 0; i < n; i++)
    {
        segSum += a[i];
        int start = i + 1;
        int mxLen = i + 1;

        int sum = 0;
        int len = 0;
        bool possible = false;
        for (int j = start; j < n; j++)
        {
            if (sum + a[j] > segSum) break;
            if (j == n - 1 and (sum + a[j]) == segSum) {
                mxLen = max(mxLen, len + 1);
                possible = true;
                break;
            }
            sum += a[j]; len++;
            if (sum == segSum) {
                mxLen = max(mxLen, len);
                sum = 0; len = 0;
            }
        }
        if (possible)
            ans = min(ans, mxLen);
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
