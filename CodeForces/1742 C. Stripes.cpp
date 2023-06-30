#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define endl '\n'
#define show(x) cout << #x << " : " << x << endl
#define files freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient ios::sync_with_stdio(0); cin.tie(0);

void solve()
{
    string grid[8];
    for (int i=0; i<8; i++)
        cin >> grid[i];


    for (int i=0; i<8; i++)
    {
        if(grid[i] == "RRRRRRRR")
        {
            cout << 'R' << '\n';
            return;
        }
    }
    cout << 'B' << '\n';
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
