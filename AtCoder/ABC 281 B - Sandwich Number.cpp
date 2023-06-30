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

/*----------------------------------------------------------------------------------------------------------------------------------------------*/

void solve()
{
    string s;
    cin >> s;

    if (s.size() > 8)
    {
        cout << "No" << endl;
        return;
    }

    if ((s[0] >= 'A' and s[0] <= 'Z') and ((s[7] >= 'A' and s[7] <= 'Z')))
    {
        string x;
        x = s.substr(1, 6);

        int n = stoi(x);

        if (n >= 100000 and n <= 999999)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    else
        cout << "No" << endl;

}

int main(void)
{
    //efficient;

    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

