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

void solve()
{
    int bun, beef, chicken; cin >> bun >> beef >> chicken;
    int beefBurgerPrice, chickenBurgerPrice; cin >> beefBurgerPrice >> chickenBurgerPrice;

    int mxPrice = max(beefBurgerPrice, chickenBurgerPrice);
    int mnPrice = min(beefBurgerPrice, chickenBurgerPrice);

    int ans = 0;
    if (mxPrice == beefBurgerPrice) {
        int bunNeed = beef * 2;
        if (bun >= bunNeed) {
            ans = beef * beefBurgerPrice;
            bun = bun - bunNeed;
        }
        else {
            int canMake = bun / 2;
            bun = 0;
            ans = canMake * beefBurgerPrice;
        }
    }
    else if (mxPrice == chickenBurgerPrice) {
        int bunNeed = chicken * 2;
        if (bun >= bunNeed) {
            ans = chicken * chickenBurgerPrice;
            bun = bun - bunNeed;
        }
        else {
            int canMake = bun / 2;
            bun = 0;
            ans = canMake * chickenBurgerPrice;
        }
    }


    if (mnPrice == beefBurgerPrice) {
        int bunNeed = beef * 2;
        if (bun >= bunNeed) {
            ans = ans + (beef * beefBurgerPrice);
            bun = bun - bunNeed;
        }
        else {
            int canMake = bun / 2;
            bun = 0;
            ans = ans + (canMake * beefBurgerPrice);
        }
    }
    else if (mnPrice == chickenBurgerPrice) {
        int bunNeed = chicken * 2;
        if (bun >= bunNeed) {
            ans = ans + (chicken * chickenBurgerPrice);
            bun = bun - bunNeed;
        }
        else {
            int canMake = bun / 2;
            bun = 0;
            ans = ans + (canMake * chickenBurgerPrice);
        }
    }
    cout << ans << endl;
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
