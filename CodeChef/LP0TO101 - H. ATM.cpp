#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(2);

    int a;
    float b;
    cin >> a >> b;
    
    if ((a%5==0) && (b-a-0.5>=0))
    {
        cout << fixed << b-a-0.5 << endl;
    }
    else
    {
        cout << fixed << b << endl;
    }

    return 0;
}
