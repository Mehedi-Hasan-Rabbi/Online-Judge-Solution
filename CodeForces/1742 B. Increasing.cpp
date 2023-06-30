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
    int n, flag = 1;
    cin >> n;

    int arr[n];
    for (int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr, arr+n);

    for (int i=n-1; i>0; i--)
    {
        if(arr[i] == arr[i-1])
            flag = 0;
    }

    if (flag == 1)
        cout << "YES" << '\n';
    else if (flag == 0)
        cout << "NO" << '\n';

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

