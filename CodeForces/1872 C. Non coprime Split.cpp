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

int is_prime (int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
    // ruturn 1 if prime, otherwaise 0
}

int divisor (int n) {
    int root = sqrt(n + 1);
    int res;
    for (int i = 2; i <= root; i++)
        if (n % i == 0) 
            res = i;
    return res;
}

void solve()
{
    int l, r; cin >> l >> r;

    if (r <= 3) {
        cout << -1 << endl;
        return;
    }
    if (l == r) {
        if (is_prime(l)) cout << -1 << endl;
        else {
            int a = divisor(l);
            cout << a << " " << l - a << endl;
        }
        return;
    }
    if (r - l >= 1) {
        cout << r / 2 << " " << r / 2 << endl;
    }
    else cout << -1 << endl;
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
