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
#define display_arr(vec)   for (auto &&it : vec){cout << it << " ";} cout << endl;
#define files              freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient          ios_base::sync_with_stdio(0); cin.tie(0);

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    ull n; cin >> n;
    ull a = 2, b, c, x;


    if (n == 1){
        cout << -1 << endl;
        return;
    }
    if (n == 2){
        a = 1; b = 1; c = 1;
    }

    else if (n%2 == 0){
        b = n / 2;
        b--;
        c = 2;
    }
    else{
        b = n / 2;
        c = 1;
    }


    if (b >= 1000000){
        if (n % 1000000 == 0){
            b = 1000000;
            a = n / 1000000;
            a--;
            x = a * b;
            c = n - x;
        }
        else{
            b = 1000000;
            a = n / 1000000;
            x = a * b;
            c = n - x;
        }
    }
    cout << a << " " << b << " " << c << endl;
}

int main(void)
{
    efficient;

    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
