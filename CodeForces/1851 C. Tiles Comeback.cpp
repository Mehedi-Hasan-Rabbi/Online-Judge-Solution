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
    int n, k; cin >> n >> k;
    vi a(n);
    input_arr(a);

    if (a[0] == a[n-1]) {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == a[0]) cnt++;
        }
        if (cnt >= k) yes;
        else no;
        return;
    }

    int first = a[0];
    int last = a[n-1];
    int cnt_first = 0;
    int cnt_last = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == first) cnt_first++;
        if (cnt_first == k) break;
    }
    
    if (cnt_first < k) {
        no;
        return;
    }

    for (int j = i + 1; j < n; j++)
    {
        if (a[j] == last) cnt_last++;
    }
    
    if (cnt_last >= k) yes;
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
