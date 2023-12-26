#include<bits/stdc++.h>
using namespace std;

const int mx = 2e5 + 123;
int a[mx], prefXOR[mx];

int main ()
{
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    for (int i = 1; i <= n; i++)
        prefXOR[i] = prefXOR[i - 1] ^ a[i];
    
    while (q--)
    {
        int l, r; cin >> l >> r;
        cout << (prefXOR[r] ^ prefXOR[l - 1]) << endl;
    }

    return 0;
}