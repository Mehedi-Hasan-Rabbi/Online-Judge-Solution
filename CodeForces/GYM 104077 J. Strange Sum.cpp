#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;

ll Maximum_Subarray_sum(vector <ll>&Name){
    ll n = Name.size();
    ll Ans = Name[0], Sum = Name[0];
    for(ll ii = 1; ii < n; ii++){
        Sum = max(Sum + Name[ii], Name[ii]);
        Ans = max(Ans, Sum);
    }
    return Ans;
}

void idea() {
    ll n;
    cin >> n;
    vector <ll> v(n);
    for(auto &ii : v) {
        cin >> ii;
    }

    sort(v.begin(), v.end());

    ll ans = 0;
    if(v[n - 1] > 0) {
        ans += v[n - 1];
    }
    if(v[n - 2] > 0) {
        ans += v[n - 2];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    for(int C = 1; C <= T; C++) {
        // cout << "Case " << C << ": " << '\n';
        idea();
    }
    return 0;
}