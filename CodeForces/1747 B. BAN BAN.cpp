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
    int n;
    cin >> n;
    if(n==1)
    {
        cout << "1" << endl;
        cout << "1 2" << endl;
        return;
    }
    int op;
    if(n%2==0)
        op=n/2;
    else
        op=(n/2)+1;
    cout << op << endl;
    int x = 2, y = n*3;

    for (int i=1; i<=op; i++)
    {
        cout << x << ' ' << y << endl;
        x+=3; y-=3;
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

