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
#define display_arr(vec)   for (auto &&it : vec){cout << it << " ";} cout << endl;
#define files              freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient          ios_base::sync_with_stdio(0); cin.tie(0);

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    int n, m; cin >> n >> m;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int ans;

    if (x1 == 1 && y1 == 1) ans = 2;
    else if (x2 == 1 && y2 == 1) ans = 2;

    else if (x1 == 1 && y1 == m) ans = 2;
    else if (x2 == 1 && y2 == m) ans = 2;

    else if (x1 == n && y1 == 1) ans = 2;
    else if (x2 == n && y2 == 1) ans = 2;

    else if (x1 == n && y1 == m) ans = 2;
    else if (x2 == n && y2 == m) ans = 2;

    else if (x1 == 1 && y1 > 1 && y1 < m) ans = 3;
    else if (x2 == 1 && y2 > 1 && y2 < m) ans = 3;

    else if (y1 == 1 && x1 > 1 && x1 < n) ans = 3;
    else if (y2 == 1 && x2 > 1 && x2 < n) ans = 3;

    else if (x1 == n && y1 > 1 && y1 < m) ans = 3;
    else if (x2 == n && y2 > 1 && y2 < m) ans = 3;

    else if (y1 == m && x1 > 1 && x1 < n) ans = 3;
    else if (y2 == m && x2 > 1 && x2 < n) ans = 3;

    else ans = 4;

    cout << ans << endl;
}

int main(void)
{
    //efficient;

    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
