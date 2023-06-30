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

    for (auto &i: v)
        cin >> i;

    for (int i=n-2; i>=0; --i)
    {
        while(v[i] !=0 and v[i]>=v[i+1])
        {
            v[i] = v[i]/2;
            ans++;
        }

        if(v[i] == v[i+1])
        {
            cout << -1 << endl;
            return;
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

