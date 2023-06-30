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

void fillPrefixSum (ll arr[], ll n, ll prefixSum[])
{
    prefixSum[0] = arr[0];
    for (ll i=1; i<n; i++)
        prefixSum[i] = prefixSum[i-1] + arr[i];
}

void solve()
{
    ll n, q;
    cin >> n >> q;
    ll arr[n], prefixSum[n];

    for (ll i=0; i<n; i++)
        cin >> arr[i];

    sort(arr, arr+n, greater<ll>());

    fillPrefixSum(arr, n, prefixSum);

    ll x, y;
    while(q--)
    {
        cin >> x >> y;
        ll ans = prefixSum[x-1] - prefixSum[x-y-1];

        if (x==y)
            ans = prefixSum[x-1];
        cout << ans << endl;

    }
}

int main(void)
{
    efficient;

    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

