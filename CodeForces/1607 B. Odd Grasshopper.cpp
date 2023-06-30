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
    ll x, n;
    cin >> x >> n;

    if (n%4 == 0)
    {
        cout << x << endl;
        return;
    }

    if (x%2 == 0)
    {
        if (n%4 == 1)
            cout << x-n << endl;
        else if (n%4 == 2)
            cout << x+1 << endl;
        else if (n%4 == 3)
            cout << x+n+1 << endl;
    }

    else
    {
        if (n%4 == 1)
            cout << x+n << endl;
        else if (n%4 == 2)
            cout << x-1 << endl;
        else if (n%4 == 3)
            cout << x-n-1 << endl;
    }
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

