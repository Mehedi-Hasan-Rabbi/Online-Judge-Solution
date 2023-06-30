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
    ll n;
    cin >> n;

    vector<ll> v(n);

    for (ll i=0; i<n; i++)
        cin >> v[i];


    ll x = v[0];
    ll mx = 2*x-1;
    ll ans = 0;

    for (ll i=1; i<n; i++)
    {
        ans = ans + (v[i]/mx);
        if (v[i]%mx == 0)
            ans--;
    }

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

