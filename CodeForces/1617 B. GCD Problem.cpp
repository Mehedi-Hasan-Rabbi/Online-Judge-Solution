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
    if (n%2 == 0)
        cout << "2 " << (n-1)-2 << " 1" << endl;
    else
    {
        int cur = (n-1)/2;
        if (cur%2 == 0)
            cout << cur-1 << " " << cur+1 << " " << 1 << endl;
        else
            cout << cur-2 << " " << cur+2 << " " << 1 << endl;
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

