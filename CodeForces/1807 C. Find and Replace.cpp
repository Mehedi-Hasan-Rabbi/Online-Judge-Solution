// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define nl               '\n'
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

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    int n; cin >> n;
    string line; cin >> line;
    
    int bin[n], atoz[27] = {0};
    for (int i = 0; i < n; i++)
    {
        if (i%2 == 0) bin[i] = 1; 
        else bin[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        char ch = line[i];
        atoz[ch-96] = bin[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        char ch = line[i];
        if (bin[i] != atoz[ch-96]){
            no;
            return;
        }
    }
    yes;
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
