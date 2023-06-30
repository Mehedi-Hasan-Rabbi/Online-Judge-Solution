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
    int n, H, M, time;
    cin >> n >> H >> M;

    time = 60*H + M;
    int ans = 24*60;

    for (int i=0; i<n; i++)
    {
        cin >> H >> M;
        int t = 60*H + M - time;

        if (t<0)
            t = t + 24*60;

        ans = min(ans, t);
    }

    cout << (ans/60) << " " << (ans%60) << endl;

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
