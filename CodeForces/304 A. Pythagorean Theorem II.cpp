#include<bits/stdc++.h>
using namespace std;

const int mx = 1e8 + 123;
bool perfect_squere[mx];

int main()
{
    int n; cin >> n;
    int ans = 0;

    for (int i = 1; i <= n; i++)
        perfect_squere[i * i] = true;
    

    for (int a = 1; a <= n; a++)
    {
        for (int b = a; b <= n; b++)
        {
            int d = (a * a) + (b * b);
            if (d > n * n) break;
            if (perfect_squere[d] == true)
                ans++;
        }
    }
    
    cout << ans << endl;
    return 0;
}