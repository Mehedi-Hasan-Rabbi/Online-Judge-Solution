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
#define showtwo(x, y)      cout << #x << " : " << x << " " << #y << " : " << y << endl
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
    int n = s.size();
    string ans(n, '*');
    vi count(26);

    for (int i = 0; i < n; i++)
        count[s[i] - 'A']++;
    
    int odd = 0, even = 0;
    for (int i = 0; i < 26; i++)
    {
        if (count[i] % 2 == 0) even++;
        else odd++;    
    }
    
    if (n % 2 == 0 and odd > 0) cout << "NO SOLUTION" << endl;
    else if (n % 2 == 1 and odd > 1) cout << "NO SOLUTION" << endl;
    else {
        int l = 0, r = n - 1;
        int odd_id;
        for (int i = 0; i < 26; i++)
        {
            if (count[i] % 2 == 0) {
                while (count[i] != 0)
                {
                    ans[l] = ans[r] = 'A' + i;
                    l++; r--;
                    count[i] -= 2;   
                }
            }
            else odd_id = i;
        }
        
        while (count[odd_id] != 0)
        {
            ans[l] = 'A' + odd_id;
            l++;
            count[odd_id]--;
        }
        cout << ans << endl;
    }
}

int main(void)
{
    efficient;

    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        solve();
    }
    return 0;
}
