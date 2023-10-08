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
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
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
#define efficient()               \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define fraction()                \
    cout.unsetf(ios::floatfield); \
    cout.precision(10);           \
    cout.setf(ios::fixed, ios::floatfield);

ll gcd(ll a, ll b)
{
    return __gcd(a, b);
}
ll lcm(ll a, ll b) { return abs(a) * (abs(b) / gcd(a, b)); }

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    int n, x;
    cin >> n >> x;
    bitset<32> x_bin(x); // O(1)
    vi book(n);

    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> book[j];
        for (int j = 0; j < n; j++)
        {
            bitset<32> book_bin(book[j]); // O(1)
            int take = 1;
            for (int bit = 31; bit >= 0; bit--)
            {
                if (x_bin[bit] == 0 and book_bin[bit] == 1)
                {
                    take = 0;
                    break;
                }
            }
            if (take)
                ans = ans | book[j];
            else
                break;
        }
    }

    if (ans == x)
        yes;
    else
        no;
}

int main(void)
{
    // efficient();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        solve();
    }
    return 0;
}
