#include<bits/stdc++.h>
using namespace std;

void solve()
{
    char ch;
    cin >> ch;

    if(ch>='a' && ch<='z')
        cout << "Lowercase character" << endl;
    else if(ch>='A' && ch<='Z')
        cout << "Uppercase character" << endl;
    else if(ch>='0' && ch<='9')
        cout << "Numerical Digit" << endl;
    else
        cout << "Special characters" << endl;
}

int main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

