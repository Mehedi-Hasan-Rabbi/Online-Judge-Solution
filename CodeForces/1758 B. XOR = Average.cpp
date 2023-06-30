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

    if (n%2 == 1)
    {
        for (int i=1; i<=n; i++)
            cout << "1" << " ";
        cout << endl;
    }
    else
    {
        for (int i=1; i<n; i++)
            cout << n+1 << " ";
        cout << 1 << endl;
    }
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
