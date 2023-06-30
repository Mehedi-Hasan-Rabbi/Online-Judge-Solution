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
    int n, q;
    cin >> n >> q;

    int red[n+1] = {0};
    int yellow[n+1] = {0};

    for (int i = 0; i < q; i++)
    {
        int q_no, x;
        cin >> q_no >> x;

        if (q_no == 1)
        {
            yellow[x]++;
        }
        else if (q_no == 2)
        {
            red[x]++;
        }
        else if (q_no == 3)
        {
            if (yellow[x] == 2 || red[x] == 1)
                yes;
            else
                no;
        }
    }
       
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
