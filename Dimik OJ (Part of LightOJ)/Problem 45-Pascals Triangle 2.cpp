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
ll pascal[51][51];
void pascal_triangle()
{
    pascal[0][0] = 1;
    pascal[1][0] = 1;
    pascal[1][1] = 1;

    for (int i = 2; i <= 50; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                pascal[i][j] = 1;
            }
            else
            {
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
        
    }  
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << pascal[i][j] << " ";
        }
        cout << "\n";
    }
    cout << '\n';
}

int main(void)
{
    //efficient;

    int t=1;
    cin>>t;
    pascal_triangle();
    while(t--)
    {
        solve();
    }
    return 0;
}
