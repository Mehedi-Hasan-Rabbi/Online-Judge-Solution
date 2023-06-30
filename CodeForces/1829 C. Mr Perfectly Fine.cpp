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
    int n; cin >> n;
    pair<int, string> skill[n];
    for (int i = 0; i < n; i++)
    {
        int t; string s;
        cin >> t >> s;
        skill[i].first = t;
        skill[i].second = s;
    }
    
    sort(skill, skill+n);

    int curr = INT_MAX, mn = INT_MAX, e = 0;
    string my = "00";
    
    for (int i = 0; i < n; i++)
    {
        if (skill[i].second == "00") continue;

        else if (skill[i].second == "11"){
            curr = skill[i].first;
            mn = min(curr, mn);
        }

        else{
            if (skill[i].second == "01" && my[1] != '1'){
                my[1] = '1'; 
                e = e + skill[i].first;
            }
            else if (skill[i].second == "10" && my[0] != '1'){
                my[0] = '1'; 
                e = e + skill[i].first;
            }

            if (my == "11"){
                curr = e;
                mn = min(curr, mn);
            }
        }
    }
    
    if (mn == INT_MAX) cout << -1 << endl;
    else cout << mn << endl;
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
