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

vi binary;
void bin(int n)
{
    int i;
    binary.push_back(0);
    for (i = 1 << 30; i > 0; i = i / 2) // For 10^9 we need 30 bit
    {
        if((n & i) != 0) binary.push_back(1);
        else binary.push_back(0);
    }
}

void solve()
{
    int n; cin >> n;
    bin(n);
    vi ans;
    ans.push_back(n);
    // display_arr(binary);
    reverse(all(binary));
    
    for (int i = 0; i < binary.size(); i++)
    {
        if (binary[i] == 1) {
            int two_power = 1 << i;
            if (n - two_power != 0) {
                n = n - two_power;
                ans.push_back(n);
            }
            else break;
        }
    }
    
    while (n != 1)
    {
        n = n / 2;
        ans.push_back(n);
    }
    cout << ans.size() << endl;
    display_arr(ans); 
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
