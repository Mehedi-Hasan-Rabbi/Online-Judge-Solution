#include<bits/stdc++.h>
using namespace std;

// Use '\n' or you will get TLE
#define endl               '\n'
#define efficient()        ios_base::sync_with_stdio(0); cin.tie(0);
const int mx = 1e5 + 123;
int a[mx];

int main()
{
    efficient();
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];

    while (q--) {
        int target; cin >> target;
        int l = 0, r = n - 1, ans = n;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (a[mid] == target) ans = min(ans, mid);
            if (a[mid] >= target) r = mid - 1;
            else l = mid + 1;
        }
        
        if (ans == n) ans = -1;

        cout << ans << endl;
    }

    return 0;
}