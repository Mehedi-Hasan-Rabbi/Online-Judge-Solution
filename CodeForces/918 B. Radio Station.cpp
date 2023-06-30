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
    int n, m;
    cin >> n >> m;

    pair<string, string> server[n];
    pair<string, string> command[m];
    string str1, str2;

    for (int i=0; i<n; i++)
    {
        cin >> str1 >> str2;
        server[i].first = str1;
        server[i].second = str2;
    }

    for (int i=0; i<m; i++)
    {
        cin >> str1 >> str2;
        command[i].first = str1;
        command[i].second = str2;
    }

    for (int i=0; i<m; i++)
    {
        str1 = command[i].second;
        str1.erase(str1.size()-1);
        for (int j=0; j<n; j++)
        {
            str2 = server[j].second;
            if (str1 == str2)
            {
                str1 = str1 + "; #" + server[j].first;
                command[i].second = str1;
                break;
            }
        }
    }

    for (int i=0; i<m; i++)
    {
        cout << command[i].first << ' ' << command[i]. second << endl;
    }
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

