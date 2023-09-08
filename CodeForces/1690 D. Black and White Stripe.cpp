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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    string first_k_seg = s.substr(0, k);
    int black = 0, white = 0;

    for (int i = 0; i < first_k_seg.size(); i++)
    {
        if (first_k_seg[i] == 'B') black++;
        else white++;        
    }
    
    int l = 0, r = k - 1;
    int ans = white;
    while (r < n - 1)
    {
        if (s[r + 1] == 'B') black++;
        else if (s[r + 1] == 'W') white++;

        if (s[l] == 'B') black--;
        else if (s[l] == 'W') white--;

        ans = min(ans, white);
        l++;
        r++;
    }
    
    cout << ans << endl;
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
