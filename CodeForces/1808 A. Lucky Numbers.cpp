// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define endl               '\n'
#define yes                cout << "YES" << endl
#define no                 cout << "NO" << endl
#define show(x)            cout << #x << " : " << x << endl
#define all(a)             a.begin(),a.end()
#define pb                 push_back
#define pf                 push_front
#define mp                 make_pair
#define ff                 first
#define ss                 second
#define display_arr(vec)   for (auto &&it : vec){cout << it << " ";} cout << endl;
#define files              freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient          ios_base::sync_with_stdio(0); cin.tie(0);

const ll MOD = 1e9 + 7; // 1000000007;

/*---------------------------------------------------------------------------------------------------------------*/

int largestDif (int n)
{
    int largest = 0;
    int smallest = 9;     
    while (n) 
    {
        int r = n % 10;
        largest = max(r, largest); 
        smallest = min(r, smallest);
        n = n / 10;
    }
    return largest - smallest;
}

void solve()
{
    int l, r; cin >> l >> r;
    int lucky = 0, differ = 0;

    if (r - l < 100)
    {
        for (int i = l; i <= r; i++)
        {
            int dif = largestDif(i);
            if(dif >= differ)
            {
                lucky = i;
                differ = dif;
            }
        }
        cout << lucky << endl;
    }
    else
    {
        for (int i = r; i >= r-100; i--)
        {
            int dif = largestDif(i);
            if(dif >= differ)
            {
                lucky = i;
                differ = dif;
            }
        }
        cout << lucky << endl;
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