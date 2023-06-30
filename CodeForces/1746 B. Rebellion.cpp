#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define endl '\n'
#define show(x) cout << #x << " : " << x << endl
#define files freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient ios::sync_with_stdio(0); cin.tie(0);

print(vi v)
{
    for (auto u:v)
        cout << u << ' ';
    cout << endl;
}

void solve()
{
    int n, x;
    cin >> n;
    vi v(n);

    for (int i=0; i<n; i++)
        cin >> v[i];
    if(is_sorted(v.begin(), v.end()))
    {
        cout << '0' << endl;
        return;
    }

    int l, r;
    for (int i=0; i<n; i++)
    {
        if (v[i] == 1)
        {
            l = i;
            break;
        }
    }

    for (int i=n-1; i>=0; i--)
    {
        if (v[i] == 0)
        {
            r = i;
            break;
        }
    }

    int cnt = 0;
    while(l<r)
    {
        if(v[l]==1 && v[r]==0)
        {
            swap(v[l], v[r]);
            cnt++;
        }

        else if(v[l] != 1)
            l++;
        else if(v[r] != 0)
            r--;
    }
    cout << cnt << endl;
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

