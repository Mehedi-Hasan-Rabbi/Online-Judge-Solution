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
    string s1, s2;
    int a, b;

    cin >> s1 >> a;
    cin >> s2 >> b;

    for (int i=s1.size()-1; i>=0; i--)
    {
        if (s1[i] == '0')
        {
            a++;
            s1.pop_back();
        }
        else
            break;
    }
    for (int i=s2.size()-1; i>=0; i--)
    {
        if (s2[i] == '0')
        {
            b++;
            s2.pop_back();
        }
        else
            break;
    }

    if (s1 == s2)
    {
        if (a>b) cout << ">" << endl;
        else if (a<b) cout << "<" << endl;
        else cout << "=" << endl;
    }

    else
    {
        int digitOfs1 = s1.size() + a;
        int digitOfs2 = s2.size() + b;

        if (digitOfs1 == digitOfs2)
        {
            if (s1>s2) cout << ">" << endl;
            else cout << "<" <<endl;
        }
        else if (digitOfs1 > digitOfs2)
            cout << ">" << endl;
        else if (digitOfs1 < digitOfs2)
            cout << "<" << endl;
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
