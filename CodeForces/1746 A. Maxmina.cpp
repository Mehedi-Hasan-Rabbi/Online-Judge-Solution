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
    int n, k, x, cnt=0;
    cin >> n >> k;
    vi vec(n);

    for (int i=0; i<n; i++)
    {
        cin >> x;
        vec.push_back(x);
        if(x==1)
            cnt=1;
    }
    if(cnt==1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

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

