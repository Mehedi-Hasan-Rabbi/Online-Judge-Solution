#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const ll ARRAY_SIZE = (ll) 2e6 + 3;

// Pair Input
template <typename typC, typename typD> 
istream &operator>>(istream &cin, pair<typC, typD> &a) {
    return cin >> a.first >> a.second;
}

// Pair Output
template <typename typC, typename typD> 
ostream &operator<<(ostream &cout, const pair<typC, typD> &a) {
    return cout << a.first << ' ' << a.second;
}

// Vector Input
template <typename typC> 
istream &operator>>(istream &cin, vector<typC> &a) {
    for (auto &x: a) cin >> x;
    return cin;
}

// Vector Output
template <typename typC> 
ostream &operator<<(ostream &cout, const vector<typC> &a) {
    int n = a.size();
    if (n == 0) return cout;
    cout << a[0];
    for (int ii = 1; ii < n; ii++) cout << ' ' << a[ii];
    return cout;
}

// Vector of Pairs Output
template <typename typC, typename typD> 
ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a) {
    for (const auto &x : a) cout << x << '\n';
    return cout;
}

// Map Output
template <typename typC, typename typD> 
ostream &operator<<(ostream &cout, const map<typC, typD> &m) {
    for (const auto &[x, y] : m) cout << x << ' ' << y << '\n';
    return cout;
}

// Set Output
template <typename typC> 
ostream &operator<<(ostream &cout, const set<typC> &s) {
    for (const auto &x : s) cout << x << ' ';
    return cout;
}

// Matrix Input
template <typename typC>
istream &operator>>(istream &cin, vector<vector<typC>> &mat) {
    for (auto &row : mat) {
        for (auto &elem : row) {
            cin >> elem;
        }
    }
    return cin;
}

// Matrix Output
template <typename typC>
ostream &operator<<(ostream &cout, const vector<vector<typC>> &mat) {
    for (const auto &row : mat) {
        for (const auto &elem : row) {
            cout << elem << ' ';
        }
        cout << '\n';
    }
    return cout;
}


ll spf[ARRAY_SIZE];
void sieve() {
    for (ll i = 1; i <= ARRAY_SIZE; i++) {
        spf[i] = i;
    }
    for (ll i = 2; i * i <= ARRAY_SIZE; i++) {
        if (spf[i] == i) { 
            for (ll j = i * i; j <= ARRAY_SIZE; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

void idea() {
    ll n, m;
    cin >> n >> m;
    vector <ll> a(n);

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    while(!a.empty() and a.back() == 1) {
        a.pop_back();
    }

    set <ll> all_spf;
    for(ll val : a) {
        while (val > 1) {
            all_spf.insert(spf[val]);
            val /= spf[val];
        }
    }

    // cout << all_spf << '\n';
    // return;
    
    
    ll ans = 1; // for x = 1, 1 <= x <= m

    vector <bool> not_coprime(m + 1, false);
    for (ll prime : all_spf) {
        for (ll mul = prime; mul <= m; mul += prime) {
            not_coprime[mul] = true;
        }
    }

    for (ll i = 2; i <= m; i++) {
        if (!not_coprime[i]) {
            ++ans;
        }
    }

    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sieve();
    int T = 1;
    cin >> T;
    for (int C = 1; C <= T; C++) {
        idea();
    }
    return 0;
}