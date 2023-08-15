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
    int n, m, row, col; cin >> n >> m >> row >> col;

    int fx, fy, sx, sy;

    if (row == 1) {
        fx = n; fy = 1;
        sx = n; sy = m;
    }

    else if (row == n) {
        fx = 1; fy = 1;
        sx = 1; sy = m;
    }

    else if (col == 1) {
        fx = 1; fy = m;
        sx = n; sy = m;
    }
    else if (col == n) {

        int dis_1 = abs(row - 1) + abs(col - 1) + abs(row - n) + abs(col - m) + abs(1 - n) + abs(1 - m);
        int dis_2 = abs(row - 1) + abs(col - m) + abs(row - n) + abs(col - 1) + abs(1 - n) + abs(m - 1);

        if (dis_1 > dis_2) {
            fx = 1; fy = 1;
            sx = n; sy = m;
        }
        else {
            fx = 1; fy = m;
            sx = n; sy = 1;
        }
    }

    else {
        fx = 1; fy = 1;
        sx = n; sy = m;
    }

    cout << fx << " " << fy << " " << sx << " " << sy << endl;
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
