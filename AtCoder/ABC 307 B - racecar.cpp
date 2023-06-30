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
    vector<string> str;
    string s, con, rev;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        str.push_back(s);
    }

    int flag = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            con = str[i] + str[j];
            rev = con;
            reverse(all(rev));
            if (con == rev) {
                cout << "Yes" << endl;
                flag = 1;
                return;
            }
        }  
    }
    
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            con = str[i] + str[j];
            rev = con;
            reverse(all(rev));
            if (con == rev) {
                cout << "Yes" << endl;
                flag = 1;
                return;
            }
        } 
    }
    
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}

int main(void)
{
    //efficient;

    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
