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

    if (n >= 1900)
        cout << "Division 1" << endl;
    else if (n >= 1600 && n<= 1899)
        cout << "Division 2" << endl;
    else if (n >= 1400 && n<=1599)
        cout << "Division 3" << endl;
    else
        cout << "Division 4" << endl;

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

