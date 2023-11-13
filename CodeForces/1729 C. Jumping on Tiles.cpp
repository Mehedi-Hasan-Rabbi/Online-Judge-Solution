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
#define efficient()        ios_base::sync_with_stdio(0); cin.tie(0);
#define fraction()         cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return abs(a) * ( abs(b) / gcd ( a, b ) ); }

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);

/*---------------------------------------------------------------------------------------------------------------*/

bool cmp1 (pair<pair<int, char>, int> &a, pair<pair<int, char>, int> &b) {
    return a.second > b.second;
}

bool cmp2 (pair<pair<int, char>, int> &a, pair<pair<int, char>, int> &b) {
    return a.second < b.second;
}

void solve()
{
    string s; cin >> s;
    int size = s.size();

    vector<pair<pair<int, char>, int>> str;
    for (int i = 0; i < size; i++)
    {
        char ch = s[i];
        str.push_back({ { i + 1, ch }, ch - 'a' });
    }

    int tot_cost = 0, m = 0;
    vi ans;
    if (s[0] > s[size - 1]) {
        sort(str.begin() + 1, str.end() - 1, cmp1);

        char curr = s[0]; m++; ans.push_back(1);
        for (int i = 1; i < size; i++)
        {
            char next = str[i].first.second;
            if (s[0] >= next and next >= s[size - 1]) {
                m++;
                int x = curr - 'a';
                int y = next - 'a';
                int cost = abs(x - y);
                tot_cost += cost;
                ans.push_back(str[i].first.first);
                curr = next;
            }
        }
        
    }

    else {
        sort(str.begin() + 1, str.end() - 1, cmp2);

        char curr = s[0]; m++; ans.push_back(1);
        for (int i = 1; i < size; i++)
        {
            char next = str[i].first.second;
            if (s[0] <= next and next <= s[size - 1]) {
                m++;
                int x = curr - 'a';
                int y = next - 'a';
                int cost = abs(x - y);
                tot_cost += cost;
                ans.push_back(str[i].first.first);
                curr = next;
            }
        }
    }

    cout << tot_cost << " " << m << endl;
    display_arr(ans);
}

int main(void)
{
    efficient();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}
