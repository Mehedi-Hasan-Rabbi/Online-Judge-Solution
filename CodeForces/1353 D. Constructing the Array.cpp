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
    vi ans(n + 1, 0);

    priority_queue< pair<int, int> > pq;
    pq.push( {n, -1} );

    int op = 1;
    while (!pq.empty())
    {
        int start = pq.top().second * -1;
        int len = pq.top().first;
        int end = start + len - 1;
        pq.pop();

        int mid;
        if (len % 2 == 0) {
            mid = (start + end - 1)  / 2;
        }
        else {
            mid = (start + end) / 2;
        }

        ans[mid] = op;
        op++;

        int seg1_s, seg1_e, seg2_s, seg2_e;
        seg1_s = start;
        seg1_e = mid - 1;

        seg2_s = mid + 1;
        seg2_e = end;

        if (seg1_s <= seg1_e) {
            int len = seg1_e - seg1_s + 1;
            pq.push( {len, seg1_s * -1} );
        }
        if (seg2_s <= seg2_e) {
            int len = seg2_e - seg2_s + 1;
            pq.push( {len, seg2_s * -1} );
        }
    }
    
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
    
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
