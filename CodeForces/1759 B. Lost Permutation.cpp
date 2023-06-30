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
    ll n, s, sum = 0;
    cin >> n >> s;

    ll arr[n];
    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr+n);

    sum = sum + s;

    for (int i=arr[n-1]; ; i++)
    {
        int n_sum = (i*(i+1)/2);
        if (n_sum <= sum)
        {
            if (n_sum==sum)
            {
                cout << "YES" << endl;
                return;
            }
            continue;
        }
        else if(n_sum > sum)
        {
            cout << "NO" << endl;
            return;
        }
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

