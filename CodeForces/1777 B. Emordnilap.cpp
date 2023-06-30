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

const ll N = 1e5+5;
vll fact(N);

void fun() 
{
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        fact[i] = fact[i-1] * i;
        fact[i] = fact[i] % MOD;
    }
}

void solve()
{
    ll n; cin >> n;
    ll ans = n * (n - 1);
    ans = ans % MOD;

    ans = (ans * fact[n]) % MOD;

    cout << ans << endl;
}

int main(void)
{
    efficient;
    
    fun();
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
