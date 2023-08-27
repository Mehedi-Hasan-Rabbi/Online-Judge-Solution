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
    string s; cin >> s;

    if (k % 2 == 0) {
        sort(all(s));
        cout << s << endl;
        return;
    }

    string odd = "";
    string even = "";

    for (int i = 0; i < n; i++)
    {
        if(i % 2 == 0) odd.push_back(s[i]);
        else even.push_back(s[i]);
    }

    sort(all(odd));
    sort(all(even));

    int odd_index = 0;
    int even_index = 0;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0) {
            cout << odd[even_index];
            even_index++;
        }
        else {
            cout << even[odd_index];
            odd_index++;
        }
    } cout << endl;
    
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
