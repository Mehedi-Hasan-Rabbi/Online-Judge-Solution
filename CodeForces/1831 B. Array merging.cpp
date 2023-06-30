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
    int n; cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    
    map<int, int> m;
    map<int, int> m_;

    int t  = a[0], curr = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == t) curr++;
        else {
            int x = max(m[t], curr);
            m[t] = x;
            curr = 0;
            t = a[i];
            curr = 1;
        }
    }
    int x = max(m[t], curr);
    m[t] = x;

    t  = b[0]; 
    curr = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == t) curr++;
        else {
            int y = max(m_[t], curr);
            m_[t] = y;
            curr = 0;
            t = b[i];
            curr = 1;
        }
    }
    int y = max(m_[t], curr);
    m_[t] = y;

    int ans = 0;
    for (auto &&i : m)
    {
        int c = i.first;
        ans = max(ans, (m[c] + m_[c]));
    }
    
    for (auto &&i : m_)
    {
        int c = i.first;
        ans = max(ans, (m[c] + m_[c]));
    }

    cout << ans << endl;
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
