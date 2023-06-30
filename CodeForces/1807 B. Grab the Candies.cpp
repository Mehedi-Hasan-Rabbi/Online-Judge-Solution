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
#define display_arr(vec)   for (auto &&it : vec){cout << it << " ";} cout << endl;
#define files              freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient          ios_base::sync_with_stdio(0); cin.tie(0);

const ll MOD = 1e9 + 7; // 1000000007;

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    int n, x; cin >> n;
    vi even, odd, candy;
    int mihai = 0, bianca = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x%2 == 0) even.push_back(x);
        else odd.push_back(x);
    }
    sort(all(even), greater<int>()); sort(all(odd));

    int sz_e = even.size(); int sz_o = odd.size();
    int e = 0, o = 0;
    while ((e != sz_e) || (o != sz_o))    
    {
        if (e != sz_e){
            candy.push_back(even[e]);
            e++;
        }
        if (o != sz_o){
            candy.push_back(odd[o]);
            o++;
        }
    }

    int flag = 0;
    for (auto &&i : candy)
    {
        if (i % 2 == 0) mihai = mihai + i;
        else bianca = bianca + i;

        if (mihai > bianca) flag = 1;
        else flag = 0;
    }
    (flag == 1) ? yes : no;
    
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
