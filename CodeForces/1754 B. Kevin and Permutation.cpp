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

    int arr[n];
    int x = (n/2)+1;

    for (int i=0; i<n; i+=2)
    {
        arr[i] = x;
        x++;
    }

    x=1;
    for (int i=1; i<n; i+=2)
    {
        arr[i] = x;
        x++;
    }

    for (int i=0; i<n; i++)
        cout << arr[i] << ' ';
    cout << endl;
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

