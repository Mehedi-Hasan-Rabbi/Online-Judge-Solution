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
#define efficient          ios_base::sync_with_stdio(0); cin.tie(0);

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    ll n, k, b, s; cin >> n >> k >> b >> s;

    if ((k * b) > s) {
        cout << -1 << endl;
        return;
    }
    
    vll ans(n);
    ll LastValue = min(s, ((k * b) + (k - 1)));
    ans[n - 1] = LastValue;

    ll remaining = s - LastValue;
    ll CanTake = (n - 1) * (k - 1);

    if (remaining > CanTake) {
        cout << -1 << endl;
        return;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (remaining > k - 1) {
            ans[i] = k -1;
            remaining = remaining - (k - 1);
        }
        else if (remaining <= k - 1) {
            ans[i] = remaining;
            remaining = 0;
        }
        else if (remaining == 0) {
            ans[i] = 0;
        }
    }
    
    display_arr(ans);
}

int main(void)
{
    //efficient;

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        solve();
    }
    return 0;
}
