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

/*---------------------------------------------------------------------------------------------------------------*/

int under(int x, int n)
{
    return n - x + 1;
}

void solve()
{
    int n, x1, x2, y1, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    if (x1 > n / 2) x1 = under(x1, n);
    if (x2 > n / 2) x2 = under(x2, n);
    if (y1 > n / 2) y1 = under(y1, n);
    if (y2 > n / 2) y2 = under(y2, n);

    int start, end;
    if (y1 >= x1) start = x1;
    else start = y1;

    if (y2 >= x2) end = x2;
    else end = y2;

    cout << abs(start - end) << endl;
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
