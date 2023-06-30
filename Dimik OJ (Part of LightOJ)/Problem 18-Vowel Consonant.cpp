#include<bits/stdc++.h>
using namespace std;

void solve()
{
    char s[10001];
    scanf(" %[^\n]", s);

    for(int i=0; s[i]!='\0'; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
                s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            cout << s[i];
    }
    cout << '\n';
    for(int i=0; s[i]!='\0'; i++)
    {
        if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' &&
                s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U' && s[i] != ' ')
            cout << s[i];
    }
    cout << '\n';
}

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

