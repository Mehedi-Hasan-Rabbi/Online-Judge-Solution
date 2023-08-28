// In the name of Allah the merciful.
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int a, b, c;
    cin >> a >> b >> c;

    int sq;
    for (int i = 1; i <= c; i++)
    {
        if (i * i >= c)
        {
            if (i * i == c)
                sq = i;
            else
                sq = i - 1;
            break;
        }
    }

    int ans = 0;
    for (int i = 1; i <= sq; i++)
    {
        if (c % i == 0)
        {
            if (i >= a && i <= b)
                ans++;
            if (c / i != i)
            {
                int d = c / i;
                if (d >= a && d <= b)
                    ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
