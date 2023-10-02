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

ll GCD ( ll a, ll b ) { return __gcd ( a, b ); }
ll LCM ( ll a, ll b ) { return abs(a) * ( abs(b) / GCD ( a, b ) ); }

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);

/*---------------------------------------------------------------------------------------------------------------*/

int getDigit (ll n, int id) {
    string number;
    while (n > 0)
    {
        int digit = n % 10;
        number.push_back(digit + '0');
        n = n / 10;
    }
    reverse(all(number));
    return number[id - 1] - '0';
}

void solve()
{
    ll k; cin >> k;
    if (k <= 9) {
        cout << k << endl;
        return;
    }

    ll val_digit = 1;
    ll val = 9;
    
    while (k - (val_digit * val) >= 0)
    {
        k = k - (val_digit * val);
        val_digit++;
        val = val * 10;
    }

    ll start = val / 9;
    start = start + (k / val_digit);
    if (k % val_digit == 0) {
        start--;
        cout << start % 10 << endl;
    }
    else {
        int id = k % val_digit;
        int ans = getDigit(start, id);
        cout << ans << endl;
    }
}

int main(void)
{
    efficient();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        solve();
    }
    return 0;
}
