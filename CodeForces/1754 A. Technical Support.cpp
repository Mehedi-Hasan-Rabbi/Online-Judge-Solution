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
    int n, count  = 0;
    cin >> n;

    string dialog;
    cin >> dialog;

    for (int i=0; i<n; i++)
    {
        if(dialog[i] == 'Q')
            ++count;
        else
            --count;

        if(count<0)
            count = 0;
    }

    if(count == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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
