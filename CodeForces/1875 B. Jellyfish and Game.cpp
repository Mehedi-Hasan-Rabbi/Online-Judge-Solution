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

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    int n, m, k; cin >> n >> m >> k;
    vi jelly(n); input_arr(jelly);
    vi gelly(m); input_arr(gelly);

    sort(all(jelly));
    sort(all(gelly));

    // First
    if (jelly[0] < gelly[m - 1])
        swap(jelly[0], gelly[m-1]);
    ull ans_o = 0;
    for (int i = 0; i < n; i++)
        ans_o += (ull) jelly[i];
    
    // Second
    sort(all(jelly));
    sort(all(gelly));

    if (gelly[0] < jelly[n-1])
        swap(gelly[0], jelly[n-1]);
    ull ans_e = 0;
    for (int i = 0; i < n; i++)
        ans_e += (ull) jelly[i];
    
    if (k % 2 == 0) cout << ans_e << endl;
    else cout << ans_o << endl;
}

int main(void)
{
    efficient();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        solve();
    }
    return 0;
}
