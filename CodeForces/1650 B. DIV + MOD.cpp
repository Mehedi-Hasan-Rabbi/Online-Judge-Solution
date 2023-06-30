// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define endl         '\n'
#define yes          cout << "Yes" << endl
#define no           cout << "No" << endl
#define show(x)      cout << #x << " : " << x << endl
#define files        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient    ios::sync_with_stdio(0); cin.tie(0);

void solve()
{
    ll l, r, a;
    cin >> l >> r >> a;

    ll ans = (r/a) + (r%a);

    if (a==1)
    {
        cout << r << endl;
        return;
    }

    if (r-(r%a)-1 >= l)
    {
        r = r-(r%a)-1;
    }

    ans = max(ans, (r/a) + (r%a));
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

