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
const double PI = acos(-1);

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    string a, b, res; cin >> a >> b;
    int f = a.size();
    int s = b.size();

    if (a == b){
        yes; cout << a << endl;
    }
    else if (a[0] == b[0]){
        yes;
        cout << a[0] << "*" << endl;
    }
    else if (a[f-1] == b[s-1]){
        yes;
        cout << "*" << a[f-1] << endl;
    }
    else {
        int ok = 0;
        for (int i = 0; i < f-1; i++)
        {
            for (int j = 0; j < s-1; j++)
            {
                if (a[i] == b[j] && a[i+1] == b[j+1]) {
                    ok = 1;
                    res.push_back(a[i]);
                    res.push_back(a[i+1]);
                    break;
                }
            }
            if (ok) break;
        }
        if (ok) {
            yes;
            cout << "*" << res << "*" << endl;
        }
        else no;
    }
}

int main(void)
{
    //efficient;

    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
