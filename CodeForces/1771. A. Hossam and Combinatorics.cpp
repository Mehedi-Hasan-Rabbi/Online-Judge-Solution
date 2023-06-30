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

/*----------------------------------------------------------------------------------------------------------------------------------------------*/

void solve()
{
    ll n;
    cin >> n;

    ll arr[n];
    for (ll i=0; i<n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    ll mx_dif = abs(arr[n-1] - arr[0]);

    ll ans = 0;
    ll f=0, l=0;
    for (ll i=0; i<n; i++)
    {
        if (arr[i] == arr[0])
            f++;
    }

    for (ll i=n-1; i>=0; i--)
    {
        if (arr[i] == arr[n-1])
            l++;
    }

    ans = (f*l)*2;

    set<ll> s;

    for (ll i=0; i<n; i++)
    {
        s.insert(arr[i]);
    }

    ll sz = s.size();

    if (sz == 1)
    {
        if (n==2)
            ans = 2;
        else
        {
            n--;
            sz = (n*(n+1))/2;
            ans = sz*2;
        }
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

