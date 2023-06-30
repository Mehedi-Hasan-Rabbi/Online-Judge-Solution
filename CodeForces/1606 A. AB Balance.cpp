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

    int ab = 0, ba = 0;

    for (int i=0; i<s.size()-1; i++)
    {

        if (s[i] == 'a' and s[i+1] == 'b')
            ab++;
        else if (s[i] == 'b' and s[i+1] == 'a')
            ba++;
    }

    if (ab == ba)
        cout << s << endl;

    else if(ab > ba)
    {
        s[0] = 'b';
        cout << s << endl;
    }

    else if(ab < ba)
    {
        s[0] = 'a';
        cout << s << endl;
    }

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

