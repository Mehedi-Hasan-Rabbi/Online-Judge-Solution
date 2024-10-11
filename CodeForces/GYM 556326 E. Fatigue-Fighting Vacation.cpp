#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void Approach(){
    ll n, a, b;
    cin >> n >> a >> b;
    vector <ll> x(a), y(b);

    for(auto &ii : x){
        cin >> ii;
    }
    for(auto &ii : y){
        cin >> ii;
        n += ii;
    }

    ll ans = b;

    for (int i = 0; i < a; i++) {
        if (n >= x[i]) {
            ans++;
            n -= x[i];
        }
        else break;
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll T = 1;
    //cin >> T;
    for(ll C = 1; C <= T; C++){
        Approach();
    }
    return 0;
}