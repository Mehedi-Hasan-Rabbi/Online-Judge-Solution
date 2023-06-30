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
    int n, x; cin >> n;
    
    map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        freq[x]++;
    }
    int mx_freq = 0;
    for (auto &&i : freq)
        mx_freq = max(i.second, mx_freq);
    
    int ans = 0;

    while (mx_freq < n)
    {
        int rem = n - mx_freq;
        int canadd = mx_freq;
        ans++;
        ans += min(canadd, rem);
        mx_freq += min(canadd, rem);
    }
    
    cout << ans << endl;
}

int main(void)
{
    //efficient;

    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
