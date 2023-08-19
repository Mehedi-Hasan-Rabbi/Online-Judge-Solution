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
    string s; cin >> s;

    int front = 0;
    int back = 0;

    for (int i = 0; i < s.size() - 1; i++)
    {
            string x;
            x.push_back(s[i]);
            x.push_back(s[i+1]);
            if (x == "()") front++;
            if (x == ")(") back++;

            x = "";
    }

    if (s == "()" or s == "(" or s == ")") {
        no;
        return;
    }

    if ((front < back) or (front * 2 == s.size()) or (back * 2 == s.size() - 1)) {
        yes;
        for (int i = 0; i < s.size(); i++) cout << "(";
        for (int i = 0; i < s.size(); i++) cout << ")";
        cout << endl;
        return;
    }

    yes;
    for (int i = 0; i < 2 * s.size(); i++)
    {
        if (i%2 == 0) cout << '(';
        else cout << ')';
    }cout << endl;
    
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