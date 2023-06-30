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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll x = a*d;
    ll y = c*b;

    if (x == y)
        cout << 0 << endl;
    else if ((x!=0 && y%x==0) || (y!=0 && x%y==0))
        cout << 1 << endl;
    else
        cout << 2 << endl;
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

