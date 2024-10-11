#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void Approach(){
    string s;
    cin >> s;

    ll k;
    cin >> k;

    ll n = s.size();

    for(ll ii = 0; ii < k; ii++){
        string t;
        t.clear();
        for(ll jj = ii; jj < n; jj += k){
            t.push_back(s[jj]);
        }
        sort(t.begin(), t.end());

        for(ll jj = ii, kk = 0; jj < n; jj += k, kk++){
            s[jj] = t[kk];
        }

    }


        cout << s << "\n";
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