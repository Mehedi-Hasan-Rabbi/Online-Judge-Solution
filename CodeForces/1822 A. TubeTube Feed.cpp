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
    int n, t; cin >> n >> t;
    vi a(n+1), b(n+1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    
    int maxEnt = 0, currEnt = 0, index = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= t){
            currEnt = b[i];
        }   
        if (currEnt > maxEnt){
            maxEnt = currEnt;
            currEnt = 0;
            index = i;
        }
        --t;
    }
    if (index == 0) cout << -1 << endl;
    else cout << index << endl;
    
}

int main(void)
{
    efficient;

    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
