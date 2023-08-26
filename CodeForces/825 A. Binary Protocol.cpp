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
    string ans = "";

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0') {
            if (cnt != 0) {
                char ch;
                if (cnt < 10) {
                    ch = 48 + cnt;
                    ans.push_back(ch);
                }
                else {
                    int f = cnt / 10;
                    int s = cnt % 10;

                    ch = 48 + f;
                    ans.push_back(ch);
                    ch = 48 + s;
                    ans.push_back(ch);
                }
            }
            cnt = 0;

            if (i != n-1 and s[i+1] == '0') ans.push_back('0'); 

        }
        else {
            cnt++;
        }
    }
    if (cnt != 0) {
        char ch;
        if (cnt < 10) {
            ch = 48 + cnt;
            ans.push_back(ch);
        }
        else {
            int f = cnt / 10;
            int s = cnt % 10;

            ch = 48 + f;
            ans.push_back(ch);
            ch = 48 + s;
            ans.push_back(ch);
        }
    }
    if (s[n-1] == '0') ans.push_back('0');
    
    cout << ans << endl;
}

int main(void)
{
    efficient;

    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
