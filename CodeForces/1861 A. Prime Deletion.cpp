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

// Prime number from 11 to 99
// 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97
void solve()
{
    string s;
    cin >> s;

    if (s[0] == '1') cout << 13 << endl;
    else if (s[0] == '2') cout << 23 << endl;
    else if (s[0] == '3') cout << 31 << endl;
    else if (s[0] == '4') cout << 41 << endl;
    else if (s[0] == '5') cout << 53 << endl;
    else if (s[0] == '6') cout << 61 << endl;
    else if (s[0] == '7') cout << 71 << endl;
    else if (s[0] == '8') cout << 83 << endl;
    else if (s[0] == '9') cout << 97 << endl;
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
