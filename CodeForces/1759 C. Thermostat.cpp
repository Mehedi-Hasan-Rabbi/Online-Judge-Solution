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
    ll l, r, x;
    cin >> l >> r >> x;
    ll a, b;
    cin >> a >> b;

    if (a==b) cout << 0 << endl;
    else if (abs(a-b)>=x) cout << 1 << endl;
    else if (abs(a-r)>=x and abs(b-r)>=x ) cout << 2 << endl;
    else if (abs(a-l)>=x and abs(b-l)>=x ) cout << 2 << endl;
    else if (abs(a-r)>=x and abs(b-l)>=x ) cout << 3 << endl;
    else if (abs(a-l)>=x and abs(b-r)>=x ) cout << 3 << endl;
    else cout << -1 << endl;

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

