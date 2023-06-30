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
#define yes                cout << "Yes" << endl
#define no                 cout << "No" << endl
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
    int n; cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >>  a[i];  
    for (int i = 0; i < n; i++)
        cin >>  b[i];
    
    for (int i = 0; i < n; i++)
        if (a[i] > b[i]) swap(a[i], b[i]);

    int maxA = *max_element(all(a));
    int maxB = *max_element(all(b));

    if (maxA == a.back() && maxB == b.back()) yes;
    else no;   

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
