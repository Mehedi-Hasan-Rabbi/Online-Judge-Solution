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
    int n, q; cin >> n >> q;
    int arr[n], pref[n], suf[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    pref[0] = arr[0]; suf[n-1] = arr[n-1];
    for (int i = 1; i < n; i++)
        pref[i] = pref[i-1] + arr[i];

    for (int i = n - 2; i >= 0; i--)
        suf[i] = suf[i+1] + arr[i];

    while (q--)
    {
        int l, r, k, sum = 0; 
        cin >> l >> r >> k;   

        if (l-2 < 0) sum = sum + 0;
        else sum = sum + pref[l-2];

        if (r == n) sum = sum + 0;
        else sum = sum + suf[r];
        
        sum = sum + abs(r-l+1) * k;

        if (sum%2 != 0) yes;
        else no;
    }
    
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
