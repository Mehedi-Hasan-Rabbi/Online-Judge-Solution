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
    int n; cin >> n;
    vi arr(n+1, 0);

    int one, two, mx;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 1) one = i;
        if (arr[i] == 2) two = i;
        if (arr[i] == n) mx = i;
    }

    if ((one < mx && mx < two) || (two < mx && mx < one))
        cout << mx << " " << mx << endl;

    else if ((one < two && two < mx) || (mx < two && two < one))
        cout << two << " " << mx << endl;
    
    else if ((two < one && one < mx) || (mx < one && one < two))
        cout << one << " "  << mx << endl;
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
