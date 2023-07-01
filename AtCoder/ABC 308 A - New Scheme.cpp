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
#define yes                cout << "Yes" << endl
#define no                 cout << "No" << endl
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
    int n = 8;
    vi v(n);
    input_arr(v);

    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (100 <= v[i] and v[i] <= 675) flag = 1;
        else {
            flag = 0; break;
        }

        if (v[i] % 25 == 0) flag = 1;
        else {
            flag = 0; break;
        }
    }
    if(flag == 0) no; 
    
    else if (flag == 1 and is_sorted(all(v))) yes;

    else no;

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
