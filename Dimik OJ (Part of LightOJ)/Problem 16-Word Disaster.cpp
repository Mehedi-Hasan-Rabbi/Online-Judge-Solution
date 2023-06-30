#include<bits/stdc++.h>
using namespace std;

void print_reverse(char str[])
{
    for (int i=strlen(str) - 1; i>=0; i--)
    {
        cout << str[i];
    }
}

void solve()
{
    char s[1002], word[1002]; // Using "string" data type will be show error because scanf(" %[^\n]", s);
    scanf(" %[^\n]", s);
    //cout << s << "\n";

    int j, k;
    for (j=0, k=0; j<strlen(s); j++)
    {
        if (s[j] != ' ')
        {
            word[k] = s[j];
            k++;
        }
        else if (k>0)
        {
            word[k] = '\0';
            print_reverse(word);
            cout << ' ';
            k = 0;
        }
    }
    if (k>0)
    {
        word[k] = '\0';
        print_reverse(word);
        cout << '\n';
    }
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
