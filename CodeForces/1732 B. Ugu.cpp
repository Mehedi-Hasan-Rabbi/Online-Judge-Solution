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
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;

    for (int i=0; i<n-1; i++)
    {
        if (s[i]=='1' and s[i+1]=='0')
            ans += 2;
    }

    if (ans > 0 and s.back() == '0')
        ans--;

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

