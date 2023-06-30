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
    ll n;
    cin >> n;
    ll a[n], b[n];
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<n; i++)
        cin >> b[i];

    ll time = 0;
    for (int i=0; i<n; i++)
    {
        if(i==n-1)
        {
            time += a[i];
            break;
        }
        if ((a[i]+b[i]+a[i+1]) <= (a[i+1]+b[i+1]+a[i]))
        {
            time += a[i];
            a[i+1] += b[i];
        }
        else
        {
            time += a[i+1];
            a[i] += b[i+1];
            swap(a[i+1], a[i]);
            swap(b[i+1], b[i]);
        }
    }
    cout << time << endl;
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
