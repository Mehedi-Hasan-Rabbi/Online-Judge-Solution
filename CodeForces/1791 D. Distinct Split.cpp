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

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vi pref(n, 0), suff(n, 0);
    set<char> line;

    for (int i = 0; i < n; i++)
    {
        line.insert(s[i]);
        pref[i] = line.size();
    }
    line.clear();
    for (int i = n-1; i >= 0; i--)
    {
        line.insert(s[i]);
        suff[i] = line.size();
    }

    int ans = 0;

    for (int i = 0; i < n-1; i++)
    {
        ans = max(ans, pref[i]+suff[i+1]);
    }
    cout << ans << endl; 
}

int main(void)
{
    //efficient;

    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
