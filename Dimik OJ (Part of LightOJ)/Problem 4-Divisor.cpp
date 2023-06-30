#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t=1, n;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        cin >> n;
        cout << "Case " << i << ":";
        for (int j=1; j<=n; j++)
        {
            if(n%j == 0)
            {
                cout << ' ' << j;
            }
        }
        cout << endl;
    }
    return 0;
}

