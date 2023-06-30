// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
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
    int odd[21], even[21], n, i, j;
    cin >> n;
 
    even[0] = 1; even[1] = 1;

    cout << 1 << endl;
    cout << even[0] << " " << even[1] << endl;
    
    for (i = 3; i <= n+1; i++)
    {
        if(i%2 == 0)
        {
            even[0] = 1;
            cout << even[0] << " ";
            for (j = 1; j < i-1; j++)
            {
                even[j] = odd[j-1] + odd[j];
                cout << even[j] << " ";
            }
            even[j] = 1;
            cout << even[j] << endl;
        }
        else
        {
            odd[0] = 1;
            cout << odd[0] << " ";
            for (j = 1; j < i-1; j++)
            {
                odd[j] = even[j-1] + even[j];
                cout << odd[j] << " ";
            }
            odd[j] = 1;
            cout << odd[j] << endl;
        }
    }
    cout << endl;  
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
