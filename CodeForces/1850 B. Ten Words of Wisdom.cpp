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

bool mycmp(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2){
    return p1.first.first > p2.first.first;
}

void solve()
{
    int n; cin >> n;
    vector<pair<pair<int, int>, int>> v;

    for (int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        v.push_back(mp(mp(b, a), i+1));
    }
    sort(all(v), mycmp);

    for (int i = 0; i < n; i++)
    {
        if(v[i].first.second <= 10){
            cout << v[i].second << endl;
            return;
        }
    }
    
}

int main(void)
{
    //efficient;

    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
