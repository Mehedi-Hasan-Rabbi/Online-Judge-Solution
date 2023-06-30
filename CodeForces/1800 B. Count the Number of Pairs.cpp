// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pi;

#define endl         '\n'
#define yes          cout << "Yes" << endl
#define no           cout << "No" << endl
#define show(x)      cout << #x << " : " << x << endl
#define files        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient    ios_base::sync_with_stdio(0); cin.tie(0);

const ll MOD = 1e9 + 7; // 1000000007;

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    ll n, k; cin >> n >> k;
    string s; cin >> s;

    ll lower[30] = {0};
    ll upper[30] = {0};

    for (ll i = 0; i < s.size(); i++)
    {
        if(s[i] >= 'a' and s[i] <= 'z')
        {
            ll x = s[i] - 96;
            lower[x]++;
        }
        else
        {
            ll x = s[i] - 64;
            upper[x]++;
        }
    }
    
    ll ans = 0;
    for (ll i = 1; i <= 26; i++)
    {
        if (lower[i] > 0 and upper[i] > 0)
        {
            ans = ans + min(lower[i], upper[i]);
            ll cnt = abs(lower[i] - upper[i]);

            if (lower[i] > upper[i])
            {
                lower[i] = cnt;
                upper[i] = 0;
            }
            else
            {
                upper[i] = cnt;
                lower[i] = 0;
            }
        }    
    }

    for (ll i = 1; i <= 26; i++)
    {
        if (lower[i] > 1)
        {
            ll c = lower[i] / 2;
            if (k > 0)
            {
                if (c >= k)
                {
                    ans = ans + k;
                    k = 0;
                }

                else
                {
                    ans = ans + c;
                    k = k - c;
                }
            }
        }

        if (upper[i] > 1)
        {
            ll c = upper[i] / 2;
            if (k > 0)
            {
                if (c >= k)
                {
                    ans = ans + k;
                    k = 0;
                }

                else
                {
                    ans = ans + c;
                    k = k - c;
                }
            }
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