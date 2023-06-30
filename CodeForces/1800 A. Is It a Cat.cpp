// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pi;

#define endl         '\n'
#define yes          cout << "YES" << endl
#define no           cout << "NO" << endl
#define show(x)      cout << #x << " : " << x << endl
#define files        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient    ios_base::sync_with_stdio(0); cin.tie(0);

const ll MOD = 1e9 + 7; // 1000000007;

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    int n; cin >> n;
    string s;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    string cat = "meow";
    string line = " ";

    line[0] = s[0];
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (line[cnt] == s[i])
        {
            continue;
        }
        else
        {
            cnt++;
            char ch = s[i];
            line.push_back(ch);
        }
    }
    
    if (line == cat)
        yes;

    else
        no;
    
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
