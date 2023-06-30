#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t, len;
    cin >> t;

    char s[1001];
    while(t--)
    {
        scanf(" %[^\n]", s);
        len = strlen(s);
        for(int i = len-1; i>=0; i--)
        {
            cout << s[i];
        }
        cout << '\n';
    }
    return 0;
}
