// In the name of Allah the merciful.
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
    int n, x, y;
    cin >> n >> x >> y;

    if((x==0 && y==0) || (x>0 && y>0))
    {
        cout << "-1" << endl;
        return;
    }
    else
    {
        int res = max(x, y);
        if (res == 1)
        {
            for (int i=2; i<=n; i++)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else if ((n-1)%res != 0)
        {
            cout << "-1" << endl;
            return;
        }
        else
        {
            for(int i=1; i<=n; )
            {
                for(int j=1; j<=res;j++)
                {
                    cout << i << ' ';
                }
                if (i==1)
                    i=i+res+1;
                else
                    i+=res;
            }
            cout << endl;
        }
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

