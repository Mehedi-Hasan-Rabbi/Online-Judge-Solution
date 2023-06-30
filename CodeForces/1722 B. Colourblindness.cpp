#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define show(x) cout << #x << " : " << x << endl
#define files freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient ios::sync_with_stdio(0); cin.tie(0);

void solve()
{
    int n;
    cin >> n;

    string row1, row2;
    cin >> row1;
    cin >> row2;
    int c=1;
    for (int i=0; i<n; i++)
    {
        if ((row1[i] == 'R' && (row2[i]=='B' || row2[i]=='G')) || (row2[i] == 'R' && (row1[i]=='B' || row1[i]=='G')))
        {
            cout << "NO" << '\n';
            c=0;
            break;
        }
    }
    if (c==1)
    {
        cout << "YES" << '\n';
    }
}

int main(void)
{
    efficient;
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }
    return 0;
}

