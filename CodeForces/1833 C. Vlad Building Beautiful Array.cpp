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

int check_even (vi arr) {
    int e = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > 0 and arr[i] % 2 == 0) e++;
    }
    return e;
}

int check_odd (vi arr) {
    int o = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > 0 and arr[i] % 2 != 0) o++;
    }
    return o;
}

void solve()
{
    int n; cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int even = check_even(v);
    int odd = check_odd(v);
    if (even == n or odd == n) {
        yes; return;
    }

    vi v1, v2;
    v1 = v; v2 = v;
    sort(all(v));
    int min_e, min_o;

    for (int i = 0; i < n; i++)
    {
        if (v[i] % 2 == 0) {
            min_e = v[i]; break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i] % 2 != 0) {
            min_o = v[i]; break;
        }
    }

    
    for (int i = 0; i < n; i++)
    {
        if (v1[i] != min_e and v1[i]%2 != 0) {
            v1[i] = v1[i] - min_e;
        }
    }
    even = check_even(v1);
    odd = check_odd(v1);
    if (even == n or odd == n) {
        yes; return;
    }

    for (int i = 0; i < n; i++)
    {
        if (v2[i] != min_o and v1[i]%2 == 0) {
            v2[i] = v2[i] - min_o;
        }
    }
    even = check_even(v2);
    odd = check_odd(v2);
    if (even == n or odd == n) {
        yes; return;
    }

    no;
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
