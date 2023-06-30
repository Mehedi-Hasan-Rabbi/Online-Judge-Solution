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
    int n, ans = 0;
    cin >> n;

    vector<int> v(n);
    for (int i=0; i<n; i++)
        cin >> v[i];

    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }

    ans = v[n-1] - v[0];

    for (int i=1; i<n; i++)
    {
        ans = max(ans, v[i]-v[0]);
    }

    for (int i=0; i<n-1; i++)
    {
        ans = max(ans, v[n-1]-v[i]);
    }

    for (int i=1; i<n; i++)
    {
        ans = max(ans, v[i-1]-v[i]);
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

