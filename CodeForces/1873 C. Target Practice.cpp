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

int cal (int row, int col) {
    int ans = 0;

    if (row == 0 or row == 9 or col == 0 or col == 9)
        return 1;
    
    else if ((row == 1 or row == 8) and (col >= 1 and col <= 8))
        return 2;
    else if ((col == 1 or col == 8) and (row >= 1 and row <= 8))
        return 2;

    else if ((row == 2 or row == 7) and (col >= 2 and col <= 7))
        return 3;
    else if ((col == 2 or col == 7) and (row >= 2 and row <= 7))
        return 3;

    else if ((row == 3 or row == 6) and (col >= 3 and col <= 6))
        return 4;
    else if ((col == 3 or col == 6) and (row >= 3 and row <= 6))
        return 4;
    
    else return 5;
}

void solve()
{
    int sum = 0;

    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            char ch; cin >> ch;
            if (ch == 'X') {
                sum += cal(row, col);
            }
        }
    }
    cout << sum << endl;
}

int main(void)
{
    //efficient;

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        solve();
    }
    return 0;
}
