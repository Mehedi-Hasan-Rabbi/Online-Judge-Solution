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
    int chef, frd;  cin >> chef >> frd;
    int x = chef, y = frd;

    if (chef % frd == 0) {
        cout << 0 << endl;
        return;
    }
    
    int res1 = INT32_MAX, cnt = 0;
    while (true)
    {
        frd--; chef++; cnt++;
        
        if (frd <= 0) break;
        if (chef % frd == 0) {
            res1 = cnt;
            break;
        }
    }

    int res2 = INT32_MAX; cnt = 0;
    chef = x, frd = y;
    while (true)
    {
        chef--; frd++; cnt++;
    
        if (chef <= 0) break;
        if (chef % frd == 0) {
            res2 = cnt;
            break;
        }
    }
    
    cout << min(res1, res2) << endl;

}

int main(void)
{
    // efficient();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}
