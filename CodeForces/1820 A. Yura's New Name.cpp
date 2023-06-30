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
    string s; cin >> s;
    string name = s;

    if (s.size() == 1 && s[0] == '^'){
        cout << 1 << endl;
        return;
    }

    for (int i = 0; i < name.size(); i++)
    {
        if (name[i] == '_'){
            if (i == 0){
                name.insert(name.begin()+i, '^');
                continue;
            }

            if (name[i-1] != '^'){
                name.insert(name.begin()+i, '^');
            }

            if (name[i+1] != '^'){
                name.insert(name.begin()+i+1, '^');
            }
        }
    }
    
    cout << name.size() - s.size() << endl;
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
