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
    vector<string> v;
    int start_col = -1;
    int start_row = -1;
    for (int i = 0; i < 8; i++)
    {
        string s = "";
        char c;
        for (int j = 0; j < 8; j++)
        {
            cin >> c;
            if (c != '.'){
                if (start_col == -1 and start_row == -1){
                start_col = j;
                start_row = i;
                }
            }
            s.push_back(c);
        }
        v.push_back(s);
    }    
    string ans = "";

    for (int i = start_row; i < 8; i++)
    {
        if (v[i][start_col] != '.'){
            ans.push_back(v[i][start_col]);
        }
    }
    cout << ans << endl;
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
