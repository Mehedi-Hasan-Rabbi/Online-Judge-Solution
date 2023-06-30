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
    int x1, x2, y1, y2;
    float r;
    cin >> x1 >> y1 >> r >> x2 >> y2;

    int x = abs(x2-x1);
    int y = abs(y2-y1);
    float distence = sqrt(x*x + y*y);

    if(distence > r)
        cout << "The point is not inside the circle" << endl;
    else
        cout << "The point is inside the circle" << endl;
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

