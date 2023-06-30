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
    int row, col;
    cin >> row >> col;

    string a = "1 0 ";
    string b = "0 1 ";
    string s1, s2;

    for (int i=0; i<2; i++)
    {
        if (i==0)
        {
            s1 = s1 + a;
            for (int j = 4; j<=col*2-2; j=j+4)
            {
                if(s1[j-2] == '0')
                    s1 = s1 + b;
                else
                    s1 = s1 + a;
            }
        }
        else
        {
            s2 = s2 + b;
            for (int j = 4; j<=col*2-2; j=j+4)
            {
                if(s2[j-2] == '1')
                    s2 = s2 + a;
                else
                    s2 = s2 + b;
            }
        }
    }

    for (int i=1; i<=row/2; i++)
    {
        if (i%2 == 1)
        {
            cout << s1 << endl;
            cout << s2 << endl;
        }
        else
        {
            cout << s2 << endl;
            cout << s1 << endl;
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
