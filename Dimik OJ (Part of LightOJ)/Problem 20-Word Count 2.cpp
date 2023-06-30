#include<bits/stdc++.h>
using namespace std;

void solve()
{
    char s[10001];
    scanf(" %[^\n]", s);

    char* word;

    word = strtok(s, ",!;?. ");
    int counter=0;

    while(word!=NULL)
    {
        if (strlen(word) > 0)
            counter++;
        word = strtok(NULL, ",!;?. ");
    }
    cout << "Count = " << counter << '\n';
}

int main(void)
{
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }
}
