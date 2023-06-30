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
    ll n, x;
    cin >> n >> x;

    ll arr[n], p[n];
    for (ll i=0; i<n; i++)
    {
        cin >> arr[i];
        p[i] = arr[i];
    }

    sort(p, p+n);

    ll r = n-1;
    ll l = 0;
    ll ans = -1;

    while(l < r)
    {
        ll y = p[r] + p[l];
        y = y%MOD;
        if ( y > x)
            r--;
        else if (y < x)
            l++;
        else if (y == x)
        {
            ans = 0;
            break;
        }
    }

    if (ans == -1)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for (ll i=0; i<n; i++)
    {
        if (p[l] == arr[i])
        {
            l = i+1;
            break;
        }
    }

    for (ll i=0; i<n; i++)
    {
        if ((p[r] == arr[i]) && (i+1 != l))
        {
            r = i+1;
            break;
        }
    }

    if (l > r)
        cout << r << " " << l << endl;
    else
        cout << l << " " << r << endl;
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

