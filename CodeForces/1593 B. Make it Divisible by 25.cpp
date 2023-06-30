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
    string s; cin >> s;
    int ans1, ans2, sz = s.size();
    ans1 = ans2 = sz;
    reverse(all(s));

    int r = 0, l = sz - 1;
    for (int i = 0; i < sz; i++)
    {
        int x;
        if (s[i] == '5') {
            r = i;
            for (int j = i+1; j < sz; j++)
            {
                if (s[j] == '2' or s[j] == '7') {
                    l = j;
                    x = r;
                    x += abs(l-r-1);
                    ans1 = min(ans1, x);
                    break;
                }
            }
        }
    }


    r = 0; l = sz - 1;
    for (int i = 0; i < sz; i++)
    {
        int x;
        if (s[i] == '0') {
            r = i;
            for (int j = i+1; j < sz; j++)
            {
                if (s[j] == '0' or s[j] == '5') {
                    l = j;
                    x = r;
                    x += abs(l-r-1);
                    ans2 = min(ans2, x);
                    break;
                }
            }
        }
    }

    cout << min(ans1, ans2) << endl;
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
