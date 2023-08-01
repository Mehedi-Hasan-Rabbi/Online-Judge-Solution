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
    int n, m; cin >> n >> m;
    vi a(n);
    input_arr(a);

    vector<ull> oneToN(n);
    vector<ull> nToOne(n);
    ull curr = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i+1]) {
            curr += (ull) a[i] - (ull) a[i+1];
        }
        oneToN[i+1] = curr;
    }

    curr = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i-1] < a[i]) {
            // show(a[i-1]); show(a[i]);
            curr += (ull) a[i] - (ull) a[i - 1];
        }
        nToOne[i-1] = curr;
    }

    int s, t;
    ull ans = 0;
    while (m--)
    {
        cin >> s >> t;
        s--; t--;
        if (s < t) {
            ans = oneToN[t] - oneToN[s];
        }
        else {
            ans = nToOne[t] - nToOne[s];
        }
        cout << ans << endl;
    }
    
}

int main(void)
{
    efficient;

    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
