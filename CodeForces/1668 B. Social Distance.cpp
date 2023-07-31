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
    ll n, m; cin >> n >> m;
    vll a(n);
    input_arr(a);
    
    if (n > m) {no; return;}

    sort(all(a), greater<int>());

    int last_marked = m - a[0];
    ll curr = 0;
    bool flag = true;

    for (int i = 0; i < n; i++)
    {
        if (i == n-1) {
            if (curr + a[i] >= m) {
                flag = false;
                break;
            }
        }

        else {
            curr += a[i] + 1;
            if (curr >= last_marked) {
                flag = false;
                break;
            }
        }
    }
    
    if(flag) yes;
    else no; 
}

int main(void)
{
    efficient;

    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
