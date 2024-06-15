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

int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, -1, +1};

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}

/*---------------------------------------------------------------------------------------------------------------*/

const int mx = 2e5 + 123;
vector<int> adj[mx];
int level[mx], parent[mx];

void bfs (int source)
{
    level[source] = 0;
    queue<int> q;
    q.push(source);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto &&v: adj[u]) {
            if (level[v] == -1) {
                level[v] = level[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

void solve()
{
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));

    int n; cin >> n;

    for (int i = 2; i <= n; i++) {
        int x; cin >> x;

        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    bfs(1);
    vector<int> path;
    path.push_back(n);
    while (parent[n] != -1) {
        path.push_back(parent[n]);
        n = parent[n];
    }
    reverse(path.begin(), path.end());
    for (auto u: path)
        cout << u << " ";
    cout << endl;
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