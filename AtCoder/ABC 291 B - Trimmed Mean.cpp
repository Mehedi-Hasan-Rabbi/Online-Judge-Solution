// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pi;

#define endl         '\n'
#define yes          cout << "Yes" << endl
#define no           cout << "No" << endl
#define show(x)      cout << #x << " : " << x << endl
#define files        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient    ios_base::sync_with_stdio(0); cin.tie(0);

const ll MOD = 1e9 + 7; // 1000000007;

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    int n, x, sum = 0;
    cin >> n;

    vi v;

    for (int i = 0; i < 5*n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    for (int i = 0 + n; i < v.size() - n ; i++)
    {
        //cout << v[i] << " ";
        sum = sum + v[i];
    }
    cout << endl;
    //show(sum);
    double grade = (double) sum / (double) (3*n);

    printf("%.15lf\n", grade);

}

int main(void)
{
    //efficient;

    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
