#include <bits/stdc++.h>
using namespace std;

#define efficient()               \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
 
void solve(void)
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x %= 2;
        x ^= 1;
        v[i] = x;
    }
    int j = 0;
    while(v[j] == 0)j++;
    for(int i = j; i < n; i++) cout << v[i];
    cout << "\n";
}
 
signed main()
{
    efficient();
    int t = 1, Test;
    cin >> t;
    for (Test = 1; Test <= t; Test++)
    {
        cout << "Case " << Test << ": ";
        solve();
    }
    return 0;
}
