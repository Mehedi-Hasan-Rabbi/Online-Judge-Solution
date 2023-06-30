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
    string str, s;
    cin >> str;

    s = "YesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYes";


    if (s.find(str) != string::npos)
    {
        cout << "Yes" << endl;
        return;
    }
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

