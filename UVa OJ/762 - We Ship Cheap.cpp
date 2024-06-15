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

int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, -1, +1};

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}

/*---------------------------------------------------------------------------------------------------------------*/

map<string, vector<string>> adj;
map<string, string> parent;
map<string, int> level;

void bfs (string source)
{
    level.clear();
    // Let, source node = level 1;
    level[source] = 1;

    queue<string> q;
    q.push(source);

    while (!q.empty())
    {
        string u = q.front();
        q.pop();

        for (auto &&v: adj[u]) {
            if (level[v] == 0) {
                level[v] = level[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

int main(void) {
    efficient();

    int n;
    bool newLine = false;
    while (cin >> n)
    {
        if (newLine) cout << endl;
        newLine = true;

        adj.clear();
        parent.clear();

        for (int i = 1; i <= n; i++) {
            string u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string s, t;
        cin >> s >> t;

        bfs(s);

        if (level[t] == 0) {
            cout << "No route" << endl;
            continue;
        }

        vector<pair<string, string>> ans;
        while (!parent[t].empty()) {
            ans.push_back( {parent[t], t} );
            t = parent[t];
        }
        reverse(ans.begin(), ans.end());

        for (auto &&u: ans)
            cout << u.first << " " << u.second << endl;
    }

    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}