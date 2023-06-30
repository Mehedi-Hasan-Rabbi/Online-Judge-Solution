#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int temp = n, res = 0;

    while(temp!=0)
    {
        int reminder = temp%10;
        res = res + (reminder * reminder * reminder);
        temp = temp / 10;
    }

    if (n == res)
    {
        cout << n << " is an armstrong number!" << endl;
    }
    else
    {
        cout << n << " is not an armstrong number!" << endl;
    }
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

