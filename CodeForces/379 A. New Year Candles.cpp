#include<bits/stdc++.h>

using namespace std;

int main(void)
{
    int a, b, res = 1;
    cin >> a >> b;

    for(int i=1; i<=a; i++)
    {
        if (i%b == 0)
        {
            res++;
        }
        res++;
    }
    cout << res << endl;
    return 0;
}
