#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



ll count(vector <ll> &a, ll n){

    ll temp[2] = {1, 0};
    ll result = 0, val = 0;

    for (ll i = 0; i + 1 <= n; i++) {

        val = ((val + a[i]) % 2 + 2) % 2;

        temp[val]++;
    }

    result = (temp[0] * temp[1]);
    return (result);

}
void Approach(){
    ll n;
    cin >> n;
    vector <ll > a(n);
    for(ll &ii : a){
        cin >> ii;
    }

    ll ans = count(a, n);

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