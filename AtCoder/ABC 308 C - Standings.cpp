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

bool cmp (pair<int, long double> a, pair<int, long double> b) {
    if (a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
}

void solve()
{
    int n; cin >> n;
    vector<pair<int, long double>> person(n+5);

    long double a, b;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        long double rate = a / (a + b);
        person[i].first = i;
        person[i].second = rate;
    }
    
    sort(person.begin()+1, person.begin()+n+1, cmp);

    for (int i = 1; i <= n; i++)
        cout << person[i].first << " ";
    cout << endl;
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
