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
    int n; cin >> n;
    vi a(n);
    input_arr(a);

    vi valley;
    set<int> s;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] != a[i+1]) {
            valley.push_back(a[i]);
            s.insert(a[i]);
        }
    }
    valley.push_back(a[n - 1]);
    s.insert(a[n - 1]);
    
    if (s.size() == 1) {
        yes;
        return;
    }


    int cnt = 0;
    for (int i = 0; i < valley.size(); i++)
    {
        if ((i == 0) and (valley[i] < valley[i + 1])) {
            cnt++;
        }
        else if ((i == valley.size() - 1) and (valley[i - 1] > valley[i])) {
            cnt++;
        }
        else if ((valley[i-1] > valley[i]) and (valley[i] < valley[i+1])) {
            cnt++;
        }            
    }
    
    if (cnt == 1) yes;
    else no;
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
