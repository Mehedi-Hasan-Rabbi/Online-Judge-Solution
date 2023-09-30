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
    int n; cin >> n;
    vi a(n); input_arr(a);
    
    vector<pair<int, int>> pos(n);
    for (int i = 0; i < n; i++)
        pos[i] = {a[i], i};
    sort(all(pos));
    reverse(all(pos));    

    map<int, int> dis;
    int coor = 1;
    for (int i = 0; i < n; i = i + 2)
    {
        int idx = pos[i].second;
        dis[idx] = coor;
        coor++;
    }
    
    coor = -1;
    for (int i = 1; i < n; i = i + 2)
    {
        int idx = pos[i].second;
        dis[idx] = coor;
        coor--;
    }

    ull tot_time = 0;
    for (auto &&i : dis)
    {
        int idx = i.first;
        ll time = (ll)a[idx] * 2LL * (ll) abs(i.second);
        tot_time = tot_time + (ull) time;
    }
    cout << tot_time << endl;
    cout << 0 << " ";
    for (auto &&i : dis)
        cout << i.second << " ";
    cout << endl;
}

int main(void)
{
    efficient;

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        solve();
    }
    return 0;
}
