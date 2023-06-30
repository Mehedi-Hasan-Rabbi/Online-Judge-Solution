#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int kount = 0;
    char line[10001];
    char ch[2];

    scanf(" %[^\n]", line);
    scanf("%s", ch);

    for (int i=0; i<strlen(line); i++)
    {
        if (line[i] == ch[0])
            kount++;
    }
    if (kount == 0)
        cout << "\'" << ch[0] << "\'" << " is not present" << endl;
    else
        cout << "Occurrence of " << "\'" << ch[0] << "\'" << " in " << "\'" << line << "\' = " << kount << endl;
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
