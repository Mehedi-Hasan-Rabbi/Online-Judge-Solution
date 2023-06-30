#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
    set<ll> s;
    
    ll n, x;
    cin >> n;
    
    for(ll i=1; i<=n; i++)
    {
        cin >> x;
        s.insert(x);
    }
    
    cout << s.size() << endl;

    return 0;
}