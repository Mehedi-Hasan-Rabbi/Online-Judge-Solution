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
    int n;
    cin >> n;
    string str;
    cin >> str;

    int x = 0, y = 0, flag = 0;

    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'U')
            y++;
        else if (str[i] == 'D')
            y--;
        else if (str[i] == 'R')
            x++;
        else if (str[i] == 'L')
            x--;
        
        if (x == 1 && y == 1)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
        printf("YES\n");
    else
        printf("NO\n");
     
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
