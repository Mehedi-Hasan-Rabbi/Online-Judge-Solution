// In the name of Allah the merciful.
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define show(x) cout << #x << " : " << x << endl
#define showtwo(x, y) cout << #x << " : " << x << " " << #y << " : " << y << endl
#define all(a) a.begin(), a.end()
#define pb push_back
#define pf push_front
#define mp make_pair
#define ff first
#define ss second
#define input_arr(vec)    \
    for (auto &&it : vec) \
    {                     \
        cin >> it;        \
    }
#define display_arr(vec)   \
    for (auto &&it : vec)  \
    {                      \
        cout << it << " "; \
    }                      \
    cout << endl;
#define files                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define efficient                 \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    string s;
    cin >> s;
    int p;
    cin >> p;
    int size = s.size();

    vi char_cnt(27);
    int price = 0;
    for (int i = 0; i < size; i++)
    {
        char_cnt[s[i] - 'a' + 1]++;
        price += s[i] - 'a' + 1;
    }

    string test = s;
    sort(all(test));

    while (price > p)
    {
        char ch = test.back();
        price -= (ch - 'a') + 1;
        char_cnt[ch - 'a' + 1]--;
        test.pop_back();
    }

    if (test.size() == 0)
        cout << test << endl;
    else
    {
        string ans = "";
        for (int i = 0; i < size; i++)
        {
            if (char_cnt[s[i] - 'a' + 1] != 0)
            {
                ans.push_back(s[i]);
                char_cnt[s[i] - 'a' + 1]--;
            }
        }
        cout << ans << endl;
    }
}

int main(void)
{
    // efficient;

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        solve();
    }
    return 0;
}
