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

void solve()
{
    int n; cin >> n;
    vector<vi> days;
    vi a(5);
    for (int i = 0; i < n; i++)
    {
        input_arr(a);
        days.push_back(a);
    }
    
    bool ok = false;
    for (int day1 = 0; day1 < 4; day1++)
    {
        for (int day2 = day1 + 1; day2 < 5; day2++)
        {
            
            int bothday = 0;
            int group_1 = 0;
            int group_2 = 0;
            bool possible = true;
            for (int i = 0; i < n; i++)
            {
                if (days[i][day1] == 0 and days[i][day2] == 0) {
                    possible = false;
                    break;
                }
                else if (days[i][day1] == 1 and days[i][day2] == 1)
                    bothday++;
                else if (days[i][day1] == 1) group_1++;
                else if (days[i][day2] == 1) group_2++;
            }
            if (possible) {
                if (group_1 > group_2) {
                    int dif = abs(group_1 - group_2);
                    if (bothday >= dif) {
                        group_2 += dif;
                        bothday -= dif;
                    }
                    else continue;
                }
                else if (group_1 < group_2) {
                    int dif = abs(group_1 - group_2);
                    if (bothday >= dif) {
                        group_1 += dif;
                        bothday -= dif;
                    }
                    else continue;
                }
                
                if (bothday % 2 == 0) {
                    group_1 += bothday / 2;
                    group_2 += bothday / 2;
                }
                else continue;

                if ((group_1 == group_2) and (group_1 + group_2 == n))
                    ok = true;
                else ok = false;
            }
            if (ok) {
                yes;
                return;
            }
            
        }
    }
    no;
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
