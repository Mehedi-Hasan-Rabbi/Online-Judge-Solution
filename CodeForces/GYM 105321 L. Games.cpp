// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

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

void solve()
{
    int n, q;
    cin >> n >> q;

    vector <int> a(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    vector <int> alice(n + 1, 0), bob(n + 1, 0), count_one(n + 1, 0);

    for(int i = 1; i <= n; i++){
        int x = a[i];
        if((x & (~(x - 1))) == x){
            alice[i] += x;
        }
        if(x & 1){
            bob[i] += x;
        }
        if(x == 1){
            count_one[i] += x;
        }
        alice[i] += alice[i - 1];
        bob[i] += bob[i - 1];
        count_one[i] += count_one[i - 1];
    }

    while(q--){
        int L, R;
        cin >> L >> R;

        ll A = alice[R] - alice[L- 1];
        ll B = bob[R] - bob[L - 1];
        ll one = count_one[R] - count_one[L - 1];

        A -= one;
        B -= one;

        if(one & 1ll){
            A += (one + 1) / 2;
            B += (one / 2);
        }
        else{
            A += (one / 2);
            B += (one / 2);
        }

        if(A > B) cout << 'A' << '\n';
        else if(B > A)  cout << 'B' << '\n';
        else cout << 'E' << '\n';
    }
}

int main(void) {
    efficient();

    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }

    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}