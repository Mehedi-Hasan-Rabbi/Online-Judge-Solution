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
#define efficient    ios_base::sync_with_stdio(0); cin.tie(0);

const ll MOD = 1e9 + 7; // 1000000007;

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    string s;
    cin >> s;
    int n = s.size();

    int pos = 0;

    for (int i = 1; i < n - 1; i++)
    {
        if (s[i] == 'a')
        {
            pos = i;
            break;
        }
    }
    
    if (pos != 0)
        cout << s.substr(0, pos) << " " << s[pos] << " " << s.substr(pos+1, n-1) << endl;
    
    else
        cout << s[0] << " " << s.substr(1, n-2) << " " << s[n-1] << endl;
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
