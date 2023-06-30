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
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b+c)
        cout << "YES" << '\n';
    else if (b == a+c)
        cout << "YES" << '\n';
    else if (c == a+b)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
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

