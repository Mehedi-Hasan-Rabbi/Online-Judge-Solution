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
    ll N, T, total = 0;
    cin >> N >> T;

    ll time[N];
    for (ll i=0; i<N; i++)
    {
        cin >> time[i];
        total = total + time[i];
    }

    ll pass = 0, song = 0, ans = 0;

    ll n = T/total;

    pass = total*n;

    for (ll i=0; ; i++)
    {
        pass = pass + time[i];
        song++;
        if (T <= pass)
        {
            ans = abs(pass - time[i] - T);
            break;
        }

        if (song == N)
        {
            song = 0;
            i = -1;
        }
    }

    cout << song << " " << ans << endl;
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

