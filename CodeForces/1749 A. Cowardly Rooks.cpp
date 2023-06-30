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
    int n, m, x, y;
    cin >> n >> m;

    pair<int, int> p[m+1];

    for (int i=1; i<=m; i++)
    {
        cin >> x >> y;
        p[i].first = x;
        p[i].second = y;
    }

    if (n == m)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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

