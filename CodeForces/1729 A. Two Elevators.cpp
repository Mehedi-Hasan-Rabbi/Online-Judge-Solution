#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define show(x) cout << #x << " : " << x << endl
#define files freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient ios::sync_with_stdio(0); cin.tie(0);

void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;

    ll f_ele = a-1;
    ll x = abs(c-b);
    ll y = abs(c-1);

    ll sec_ele = x + y;


    if(f_ele < sec_ele)
        cout << "1" << '\n';
    else if(sec_ele < f_ele)
        cout << "2" << '\n';
    else
        cout << "3" << '\n';
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

