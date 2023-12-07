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
#define files()            freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient()        ios_base::sync_with_stdio(0); cin.tie(0);
#define fraction()         cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return abs(a) * ( abs(b) / gcd ( a, b ) ); }

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    ll days, tot_p, lesson_p, week_p;
    cin >> days >> tot_p >> lesson_p >> week_p;

    ll week_task;
    if (days % 7 == 0) week_task = days / 7;
    else week_task = (days / 7) + 1;

    // show(week_task);
    
    int ans = 0;
    int day = 0;
    // Week task ses korte time lagbe
    ll time = week_task / 2;
    // proti din kaj korle point pabo
    ll point = (2 * week_p) + lesson_p;
    // tot piont the din lagbe;
    if (tot_p % point == 0) 
        day = tot_p / point;
    else 
        day = (tot_p / point) + 1;

    if (time >= day) {
        cout << days - day << endl;
        return;
    }
    else {
        tot_p -= (time * point);
        ans += time;
    }
    
    // showtwo(tot_p, ans);

    // Jodi week task odd hoi
    if (week_task % 2 == 1) {
        tot_p -= (week_p + lesson_p);
        ans++;
    }
    
    // showtwo(tot_p, ans);


    if (tot_p <= 0) {
        cout << days - ans << endl;
        return;
    }

    if (tot_p % lesson_p == 0) 
        ans += (tot_p / lesson_p);
    else
        ans += ( (tot_p / lesson_p) + 1 );
    
    cout << days - ans << endl;
}

int main(void)
{
    //efficient();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}
