// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
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
    int n;
    cin >> n;

    if (n==1)
        cout << 1 << endl;
    else if (n==3)
        no;
    else if (n%2==0)
    {
        yes;
        for (int i = 1; i <= n/2; i++)
        {
            cout << "1 -1 "; 
        }
        cout << endl;
    }
    else if (n%2!=0)
    {
        int nth_odd = (n/2)-1;
        yes;
        for (int i = 1; i <= n/2; i++)
        {
            cout << nth_odd << " -" << nth_odd+1 << " "; 
        }
        cout << nth_odd << endl;
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
