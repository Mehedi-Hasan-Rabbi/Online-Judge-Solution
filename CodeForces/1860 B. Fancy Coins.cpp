// In the name of Allah the merciful.
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define show(x) cout << #x << " : " << x << endl
#define showt(x, y) cout << #x << " : " << x << " " << #y << " : " << y << endl
#define all(a) a.begin(), a.end()
#define pb push_back
#define pf push_front
#define mp make_pair
#define ff first
#define ss second
#define input_arr(vec)    \
    for (auto &&it : vec) \
    {                     \
        cin >> it;        \
    }
#define display_arr(vec)   \
    for (auto &&it : vec)  \
    {                      \
        cout << it << " "; \
    }                      \
    cout << endl;
#define files                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define efficient                 \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    int m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;

    // Total coins need.
    int need_1 = m % k;
    int need_k = m / k;
    
    // Fancy coins need (Total need - What I have)
    int need_fancy_1 = max(0, need_1 - a1);
    int need_fancy_k = max(0, need_k - ak);

    // Unused Regular coins worth 1
    int unused_regular_coin_1 = max(0, a1 - need_1);

    // How much Unused Regular_1 can be replaced with Regular_k
    int to_replace = min(unused_regular_coin_1 / k, need_fancy_k);

    int ans = need_fancy_1 + need_fancy_k - to_replace;

    cout << ans << endl;
    
}

int main(void)
{
    // efficient;

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
