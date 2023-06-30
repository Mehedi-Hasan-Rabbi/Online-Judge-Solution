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
    ll n, s1=0, s2=0, x;
    cin >> n;

    for (ll i=1; i<=n; i++)
    {
        cin >> x;
        if(x<=0)
            s1 += abs(x);
        else
            s2 += x;
    }

    cout << abs(s1-s2) << endl;
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

