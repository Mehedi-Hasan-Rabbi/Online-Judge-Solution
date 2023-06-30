// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define endl '\n'
#define show(x) cout << #x << " : " << x << endl
#define files freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient ios::sync_with_stdio(0); cin.tie(0);

void solve()
{
    ll n, one = 0, zero = 0, ans = 0, con_one = 0, con_zero = 0;
    cin >> n;
    string str;
    cin >> str;

    for (ll i=0; i<str.size(); i++)
    {
        if (str[i] == '0')
            zero++;
        else
            one++;
    }
    ans = max(zero*one, ans);
    //cout << ans << endl;

    char ch = '1';
    ll cnt = 0;
    for (ll i=0; i<str.size(); i++)
    {
        if(str[i] == ch)
        {
            cnt++;
        }
        else
        {
            con_one = max(cnt, con_one);
            cnt = 0;
        }
    }
    con_one = max(cnt, con_one);
    //show(con_one);

    ch = '0';
    cnt = 0;
    for (ll i=0; i<str.size(); i++)
    {
        if(str[i] == ch)
        {
            cnt++;
        }
        else
        {
            con_zero = max(cnt, con_zero);
            cnt = 0;
        }
    }
    con_zero = max(cnt, con_zero);
    //show(con_zero);

    ans = max(con_zero*con_zero, ans);
    ans = max(con_one*con_one, ans);

    cout << ans << endl;
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

