// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/Debug.h"
#else
#define dbg(...)
#endif

typedef long long ll;
typedef unsigned long long ull;

#define endl               '\n'
#define efficient()        ios_base::sync_with_stdio(0); cin.tie(0);
#define fraction()         cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return abs(a) * ( abs(b) / gcd ( a, b ) ); }

int dx[] = {+1, -1, 0, 0, +1, +1, -1, -1};
int dy[] = {0, 0, -1, +1, +1, -1, +1, -1};

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}

/*---------------------------------------------------------------------------------------------------------------*/

vector<int> primeFactors(int n) 
{
    vector<int> div;
    while (n % 2 == 0) { 
        div.push_back(2);
        n = n / 2; 
    }

    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) { 
            div.push_back(i);
            n = n / i; 
        } 
    } 
    
    if (n > 2) 
        div.push_back(n);
    
    return div;
}

void July_36_2024()
{
    int n; cin >> n;
    vector<int> a(n, 0);

    map<int, int> divisors;
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        vector<int> div = primeFactors(a[i]);
        for (auto &&u : div)
            divisors[u]++;
    }

    bool ok = true;
    for (auto [key, value]: divisors) {
        if (value % n != 0) {
            ok = false;
            break;
        }
    }

    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(void) {
    efficient();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        // cout << "Case " << tc << ": ";
        July_36_2024();
    }

    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}