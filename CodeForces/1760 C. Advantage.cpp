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
    ll n, x;
    cin >> n;

    vector<ll> v, temp;

    for (ll i=0; i<n; i++)
    {
        cin >> x;
        v.push_back(x);
        temp.push_back(x);
    }

    sort(temp.begin(), temp.end());

    for (ll i=0; i<n; i++)
    {
        if (v[i] < temp[n-1])
        {
            cout << v[i]-temp[n-1] << " ";
        }

        else
            cout << v[i]-temp[n-2] << " ";
    }
    cout << endl;

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

