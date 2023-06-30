// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define endl '\n'
#define show(x) cout << #x << " : " << x << endl
#define files freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient ios::sync_with_stdio(0); cin.tie(0);

void solve()
{
    int n;
    cin >> n;

    for (int i=1; i<=n; i+=2)
        cout << i << ' ';

    if (n%2!=0)
    {
        for (int i=n-1; i>=1; i-=2)
            cout << i << ' ';
    }
    else
    {
        for (int i=n; i>=1; i-=2)
            cout << i << ' ';
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

