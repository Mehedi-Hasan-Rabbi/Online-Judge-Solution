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
    int n; cin >> n;
    vector<string> word;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        word.push_back(s);
    }

    string secret = word[0];
    map<string, int> freq;

    for (int i = 0; i < n; i++) {
        string curr = word[i];

        for (int j = 0; j < 5; j++) {
            bool fnd = false;
            for (int k = 0; k < 5; k++) {
                if (curr[j] == secret[k]) {
                    if (j == k) curr[j] = '*';
                    else curr[j] = '!';
                    fnd = true;
                }
            }
            if (!fnd) curr[j] = 'X';
        }
        freq[curr]++;
    }

    int q; cin >> q;
    while (q--)
    {
        string s; cin >> s;
        cout << freq[s] << endl;
    }
}

int main(void) {
    // efficient();

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