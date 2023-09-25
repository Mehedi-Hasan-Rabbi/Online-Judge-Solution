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
    int n, m; cin >> n >> m;
    vector<vll> chess;

    for (int i = 0; i < n; i++)
    {
        vll test(m);
        for (int j = 0; j < m; j++)
            cin >> test[j];
        chess.push_back(test);
    }
    
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int index = 0;
            ll sum = 0;

            while (i - index > -1 and j - index > -1) // Up left diagonal
            {
                sum += chess[i - index][j - index];
                index++;
            }
            index = 0;
            while (i - index > -1 and j + index < m) // Up right diagonal
            {
                sum += chess[i - index][j + index];
                index++;
            }
            index = 0; 
            while (i + index < n and j - index > -1)
            {
                sum += chess[i + index][j - index];
                index++;
            }
            index = 0; 
            while (i + index < n and j + index < m)
            {
                sum += chess[i + index][j + index];
                index++;
            }
            
            sum = sum - 3 * chess[i][j];
            ans = max(ans, sum);
        }
    }
    
    cout << ans << endl;
}

int main(void)
{
    // efficient;

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        solve();
    }
    return 0;
}