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
    int n, flag = 0; cin >> n;
    vll v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    ll gcd1 = v[0], gcd2 = v[1];
    
    string s1, s2;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0) {
            s1.push_back('0'); s2.push_back('1');
        }
        else {
            s1.push_back('1'); s2.push_back('0');
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if (i%2 == 0) gcd1 = __gcd(gcd1, v[i]);
        else gcd2 = __gcd(gcd2, v[i]);
    }
    
    string ans1, ans2;
    for (int i = 0; i < n; i++)
    {
        if (v[i] % gcd1 == 0) ans1.push_back('1');
        else ans1.push_back('0');

        if (v[i] % gcd2 == 0) ans2.push_back('1');
        else ans2.push_back('0');
    }
    
    if (ans1 == s1 or ans1 == s2) cout << gcd1 << endl;
    else if (ans2 == s1 or ans2 == s2) cout << gcd2 << endl;
    else cout << 0 << endl;
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
