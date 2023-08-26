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

void solve()
{
    char ch;
    int start_h, start_m; cin >> start_h >> ch >> start_m;
    int end_h, end_m; cin >> end_h >> ch >> end_m;

    int start_in_min = (start_h * 60) + start_m;  // converting hour into min
    int end_in_min = (end_h * 60) + end_m;        // converting hour into min


    int duration = (start_in_min - end_in_min);
    if (duration < 0) duration = abs(duration);  // Starting time is less than ending time
    else {                                       // Starting time is greather than ending time
        int first = 1440 - start_in_min;         // 24:00 = 1440 
        int second = end_in_min;
        duration = first + second;
    }

    start_in_min = start_in_min + (duration / 2);
    int hour = start_in_min / 60;
    int min = start_in_min % 60;

    if (hour >= 24) {
        hour = abs(24 - hour);
    }
    
    string ans_h = to_string(hour);
    string ans_m = to_string(min);

    if (ans_h.size() != 2) ans_h = '0' + ans_h;
    if (ans_m.size() != 2) ans_m = '0' + ans_m;

    cout << ans_h << ':' << ans_m << endl;
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
