#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[123][123], b[123], c[123];

    int n, m; cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];        
    }
    
    for (int i = 1; i <= m; i++) cin >> b[i];
    
    for (int k = 1; k <= n; k++)
    {
        c[k] = 0;
        for (int i = 1; i <= m; i++)
        {
            c[k] += (a[k][i] * b[i]);
        }
        cout << c[k] << endl;
    }
    
    return 0;
}