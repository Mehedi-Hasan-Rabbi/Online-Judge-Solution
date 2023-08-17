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

bool cmp (vi a, vi b) {
    return a[1] < b[1];
}

void solve()
{
    int n; cin >> n;
    vector<vector<int>> data;

    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        vector<int> a(x);
        for (int j = 0; j < x; j++) cin >> a[j];
        
        sort(all(a));
        data.push_back(a);
    }

    sort(all(data), cmp);

    ll sum = 0;
    vi first;
    first.push_back(data[0][0]);

    for (int i = 1; i < n; i++)
    {
        sum = sum + (ll)(data[i][1]);
        first.push_back(data[i][0]);
    }
    
    sort(all(first));

    sum += (ll)(first[0]);

    cout << sum << endl;
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
