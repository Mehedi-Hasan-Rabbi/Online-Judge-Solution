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

const ll MOD = 1e9 + 7; // 1000000007;

void solve()
{
    ll n, ans = 0;
    cin >> n;

    vector<ll> v(n);

    for (auto &u:v)
        cin >> u;

    for (ll i=0; i<n-1; i++)
    {
        if (v[i] == 0)
            --ans;
        else
            break;
    }

    sort(v.begin(), v.end()-1);
    for (ll i=0; i<n-1; i++)
    {
        if (v[i] == 0)
            ans++;
        else
        {
            ans = ans + v[i];
        }
    }

    cout << ans << endl;
}

int main(void)
{
    efficient;

    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
