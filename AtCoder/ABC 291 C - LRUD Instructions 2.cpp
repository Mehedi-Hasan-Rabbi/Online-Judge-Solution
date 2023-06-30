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
    int n;       cin >> n;
    string s;    cin >> s;

    pair<int, int> co[n+1];

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'R')
        {
            co[i+1].first = co[i].first + 1;
            co[i+1].second = co[i].second;
        }

        else if (s[i] == 'L')
        {
            co[i+1].first = co[i].first - 1;
            co[i+1].second = co[i].second;
        }

        else if (s[i] == 'U')
        {
            co[i+1].first = co[i].first;
            co[i+1].second = co[i].second + 1;
        }

        else if (s[i] == 'D')
        {
            co[i+1].first = co[i].first;
            co[i+1].second = co[i].second - 1;
        }
    }
        
    
    set< pair<int,int> > set1; 
    for (int i = 0; i < n+1; i++)
    {
        set1.insert(make_pair(co[i].first, co[i].second));
    }
    
    if (set1.size() != n+1)
        cout << "Yes" << endl;
    
    else
        cout << "No" << endl;

    set1.clear();
}

int main(void)
{
    efficient;

    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
