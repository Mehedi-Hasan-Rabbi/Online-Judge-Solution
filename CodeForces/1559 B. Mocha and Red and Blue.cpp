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
    string s; cin >> s;

    int l = -1, r = - 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '?') {
            l = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] != '?') {
            r = i;
            break;
        }
    }
    if (l == -1 or r == -1) {
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0) cout << "B";
            else cout << "R";
        }
        cout << endl;
        return;
    }

    for (int i = l - 1; i >= 0; i--)
    {
        if (s[i+1] == 'R') s[i] = 'B';
        else s[i] = 'R';
    }
    for (int i = r + 1; i < n; i++)
    {
        if (s[i-1] == 'R') s[i] = 'B';
        else s[i] = 'R';
    }
    
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '?') {
            if (s[i-1] == 'R') s[i] = 'B';
            else s[i] = 'R';
        }
    }
    
    cout << s << endl;
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
