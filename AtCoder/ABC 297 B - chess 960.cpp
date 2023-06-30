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
#define yes                cout << "Yes" << endl
#define no                 cout << "No" << endl
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

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    string s; cin >> s;
    string test; int num = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'R' || s[i] == 'K') test = test + s[i];
        else if (s[i] == 'B') num = num + i;
    }
    if (num%2 == 1 and test =="RKR") yes;
    else no;
}

int main(void)
{
    efficient;

    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
