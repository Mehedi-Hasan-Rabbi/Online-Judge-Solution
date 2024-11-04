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

// for (auto [key, val]: freq) {
//         cout << key << ": " << endl;
//         for (auto u: val) cout << u << " ";
//         cout << endl;
//     }

void solve()
{
    int n; cin >> n;
    vector<string> dictonary;
    map<string, vector<int>> freq;
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        dictonary.push_back(str);

        vector<int> count(26);
        for (auto ch: str) count[ch - 'a']++;

        freq[str] = count;
    }

    int q; cin >> q;
    while (q--)
    {
        string s; cin >> s;
        vector<int> count(26);
        for (auto u: s) count[u - 'a']++;

        int ans = 0;
        for (auto word: dictonary) {
            bool anagram = true;
            for (int i = 0; i < 26; i++) {
                if (freq[word][i] > count[i]) {
                    anagram = false;
                    break;
                }
            }

            (anagram == true) ? ans++ : ans;
        }
        cout << ans << endl;
    }
    
}

int main(void) {
    efficient();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cout << "Case " << tc << ":\n";
        solve();
    }

    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}