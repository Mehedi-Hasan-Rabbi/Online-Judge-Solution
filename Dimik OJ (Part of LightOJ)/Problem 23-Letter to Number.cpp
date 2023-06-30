#include<bits/stdc++.h>
using namespace std;

/*
void solve()
{
    string line;
    cin >> line;

    for (int i=0; i<line.size(); i++)
    {
        if (line[i] >= 'A' && line[i] <= 'Z')
        {
            cout << line[i]-64;
        }
    }
    cout << endl;
}
*/
void solve()
{
    string line;
    cin >> line;

    for (int i=0; i<line.size(); i++)
    {
        cout << line[i] - 'A' + 1;
    }
    cout << endl;
}

int main(void)
{
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

