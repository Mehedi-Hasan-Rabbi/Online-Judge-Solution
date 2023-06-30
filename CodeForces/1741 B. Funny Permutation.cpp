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

void solve()
{
    int n;
    cin >> n;

    if (n==3)
    {
        cout << -1 << endl;
        return;
    }
    else if (n%2 == 0)
    {
        for (int i=n; i>(n/2); i--)
            cout << i << " ";

        for (int i=1; i<=(n/2); i++)
            cout << i << " ";
    }
    else
    {
        for (int i=n; i>(n/2)+1; i--)
            cout << i << " ";

        for (int i=1; i<=(n/2)+1; i++)
            cout << i << " ";
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

