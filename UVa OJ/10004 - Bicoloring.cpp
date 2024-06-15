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

const int mx = 300;
vector<int> adj[mx];
int color[mx];

bool isBipartite (int source)
{
    memset(color, -1, sizeof(color));

    color[source] = 1;
    queue<int> q;
    q.push(source);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto &&v: adj[u]) {
            if (color[v] == -1) {
                if (color[u] == 1) color[v] = 2;
                else color[v] = 1;

                q.push(v);
            }
            else if (color[u] == color[v]) return false;
        }
    }

    return true;
}

int main(void) {
    efficient();

    int n;
    while (cin >> n)
    {
        if (n == 0) break;

        for (int i = 0; i < mx; i++) adj[i].clear();

        int m; cin >> m;
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        if (isBipartite(0)) cout << "BICOLORABLE." << endl;
        else cout << "NOT BICOLORABLE." << endl;
    }

    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}