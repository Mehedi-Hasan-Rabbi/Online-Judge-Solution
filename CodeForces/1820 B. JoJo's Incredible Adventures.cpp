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

int maxConsequtiveOne(string str)
{
    ll cnt = 0;
    for (int i = 0; i < str.size();)
    {
        ll curr_cnt = 0;
        if (str[i] == '1'){
            while (i < str.size() && str[i] == '1')
            {
                curr_cnt++;
                i++;
            }
            
        }
        else i++;

        if (curr_cnt > cnt){
            cnt = curr_cnt;
            curr_cnt = 0;
        }
    }
    return cnt;
}

int suffConse(string str)
{
    ll res = 0;
    for (int i = 0; i < str.size(); i++){
        if(str[i] == '1') res++;
        else break;
    }
    return res;
}

int prefConse(string str)
{
    ll res = 0;
    for (int i = str.size() - 1; i >= 0; i--){
        if(str[i] == '1') res++;
        else break;
    }
    return res;
}

void solve()
{
    string s;
    cin >> s;
    ll n = s.size();

    ll conse_one = maxConsequtiveOne(s);
    
    if (conse_one == n){
        ull ans = n*n;
        cout << ans << endl;
        return;
    }
    
    if (conse_one == 0){
        cout << 0 << endl;
        return;
    }

    ll len = 0;
    if (s[0] == '1' and s[s.size() - 1] == '1' and s.size() != 1){
        int suff = suffConse(s);
        int pref = prefConse(s);

        len = suff + pref;
    }    

    len = max(conse_one, len);
    len++;
    ll height = len / 2;
    ll wid = len - height;
    cout << height * wid << endl;
}

int main(void)
{
    //efficient;

    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
