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
    string s, t; cin >> s >> t;
    vi pos;

    for (int i = t.size() - 1; i >= 0; i--)
    {
        for (int j = s.size() - 1; j >= 0; j--)
        {
            if (s[j] == t[i]) {
                pos.push_back(j);
                s[j] = '0';
                break;
            }
        }
    }
    
    reverse(all(pos));
    
    int flag = 1;
    for (int i = 1; i < pos.size(); i++)
    {
        if (pos[i-1] > pos[i]) {
            flag = 0;
            break;
        }
    }
    
    if (pos.size() != t.size()) flag = 0;
    
    if (flag) yes;
    else no;
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
