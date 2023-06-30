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
#define display_arr(vec)   for (auto &&it : vec){cout << it;} cout << endl;
#define files              freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient          ios_base::sync_with_stdio(0); cin.tie(0);

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    int n; cin >> n;

    int flag = 0;
    int first = -1, last = -1, num;
    while (n--)
    {
        cin >> num;

        if (flag) {
            if (last <= num and first >= num) {
                cout << 1;
                last = num;
            }
            else cout << 0;
        }
        else {
            if (first == -1) {
                cout << 1;
                first = num;
                last = num;
            }
            else if (last <= num) {
                cout << 1;
                last = num;
            }
            else if (last > num and first >= num) {
                cout << 1;
                flag = 1;
                last = num;
            }
            else cout << 0;
        }
    }
    cout << endl;
}

int main(void)
{
    efficient;

    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
