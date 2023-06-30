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
    string a, b;
    cin >> a >> b;

    char la = a.back();
    char lb = b.back();

    if (la == lb)
    {
        int c1 = a.size();
        int c2 = b.size();

        if(c1==c2)
            cout << "=" << endl;

        else if (la == 'S')
        {
            cout << (c1 > c2 ? '<' : '>') << endl;
        }
        else
            cout << (c1 > c2 ? '>' : '<') << endl;
    }

    else
    {
        if(la == 'L' && lb =='M')
            cout << ">" << endl;
        if(la == 'M' && lb =='L')
            cout << "<" << endl;
        if(la == 'M' && lb =='S')
            cout << ">" << endl;
        if(la == 'S' && lb =='M')
            cout << "<" << endl;
        if(la == 'L' && lb =='S')
            cout << ">" << endl;
        if(la == 'S' && lb =='L')
            cout << "<" << endl;
    }

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
