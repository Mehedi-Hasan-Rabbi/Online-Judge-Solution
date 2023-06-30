// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define nl               '\n'
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

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int cnt = 0;

    if (a == c && b == d)
    {
        cout << 0 << endl;
        return;
    }
    if (b > d)
    {
        cout << -1 << endl;
        return;
    }
    while (b != d)
    {
        a = a + 1;
        b = b + 1;
        cnt++;
    }
    if(a >= c)
    {
        cnt = cnt + abs(a - c);
        cout << cnt << endl;
    }
    else  cout << -1 << endl;

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
