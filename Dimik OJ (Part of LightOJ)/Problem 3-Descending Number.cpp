#include<bits/stdc++.h>

using namespace std;

int main(void)
{
    for (int i=1000; i>=1; i--)
    {
        if (i%5==0 & i!=1000)
            cout << endl;
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
