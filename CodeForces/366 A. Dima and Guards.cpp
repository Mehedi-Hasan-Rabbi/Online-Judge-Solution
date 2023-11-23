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

int grd = 0, ff = -1, ss = -1;
void dorm (int a, int b, int c, int d, int g, int n) {
    if (a + c <= n) {
        grd = g;
        ff = a;
        ss = n - a;
    }
    else if (a + d <= n) {
        grd = g;
        ff = a;
        ss = n - a;
    }
    else if (b + c <= n) {
        grd = g;
        ff = b;
        ss = n - b;
    }
    else if (b + d <= n) {
        grd = g;
        ff = b;
        ss = n - b;
    }
}

int main(void)
{
    efficient();

    int n; cin >> n;
    int a, b, c, d; 
    
    cin >> a >> b >> c >> d;
    dorm (a, b, c, d, 1, n);

    cin >> a >> b >> c >> d;
    dorm (a, b, c, d, 2, n);

    cin >> a >> b >> c >> d;
    dorm (a, b, c, d, 3, n);

    cin >> a >> b >> c >> d;
    dorm (a, b, c, d, 4, n);
    
    if (ff == -1 and ss == -1) cout << -1 << endl;
    else cout << grd << " " << ff << " " << ss << endl;
    return 0;
}
