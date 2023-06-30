#include<bits/stdc++.h>
using namespace std;

void solve()
{
    char s[10001];
    scanf(" %[^\n]", s);

    int counter=0;
    for (int i=0; s[i]!='\0'; i++)
    {
        if (s[i]==' ')
            counter++;
    }
    cout << "Count = " << counter+1 << '\n';
}

int main(void)
{
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }
    return 0;
}
