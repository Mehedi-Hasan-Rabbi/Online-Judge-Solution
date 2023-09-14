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
    int n; cin >> n;
    vi ans(n + 1);

    string s; cin >> s;


    int half = half = (n / 2) - 1;

    int same = 0, not_same = 0;
    for (int i = 0; i <= half; i++)
    {
        if (s[i] == s[(n-1) - i]) same++;
        else not_same++;
    }

    int put_one = not_same;
    ans[put_one] = 1;
    ans[n - put_one] = 1;

    for (int i = put_one; i <= n - put_one; i = i + 2)
        ans[i] = 1;
    
    if (n % 2 == 1) {
        for (int i = put_one + 1; i <= n - put_one; i = i + 2)
        ans[i] = 1;
    }

    // Show ans
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i];
    cout << endl;
    
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
