// In the name of Allah the merciful.
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define show(x) cout << #x << " : " << x << endl
#define showtwo(x, y) cout << #x << " : " << x << " " << #y << " : " << y << endl
#define all(a) a.begin(), a.end()
#define pb push_back
#define pf push_front
#define mp make_pair
#define ff first
#define ss second
#define input_arr(vec)    \
    for (auto &&it : vec) \
    {                     \
        cin >> it;        \
    }
#define display_arr(vec)   \
    for (auto &&it : vec)  \
    {                      \
        cout << it << " "; \
    }                      \
    cout << endl;
#define files                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define efficient                 \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);

/*---------------------------------------------------------------------------------------------------------------*/

bool check (vi arr, int n) {
    bool found = false;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == n) {
            found = true;
            break;
        }
    }
    return found;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> sets;
    vi allUnion;

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        vi set(k);
        for (int i = 0; i < k; i++)
        {
            cin >> set[i];
            allUnion.push_back(set[i]);
        }
        sets.push_back(set);
    }
    sort(all(allUnion));
    allUnion.erase(unique(all(allUnion)), allUnion.end());
    
    
    int ans = 0;
    for (int except = 1; except <= 50; except++)
    {
        bool found = false;
        vi exceptUnion;
        // Checking except value is in the set or not.
        for (int i = 0; i < n; i++)
        {
            found = check(sets[i], except);
            if (found == false) {
                for (int j = 0; j < sets[i].size(); j++)
                    exceptUnion.push_back(sets[i][j]);
            }
        }
        sort(all(exceptUnion));
        exceptUnion.erase(unique(all(exceptUnion)), exceptUnion.end());

        if (exceptUnion.size() < allUnion.size()) {
            int size = exceptUnion.size();
            ans = max(ans, size);
        }
    }
    cout << ans << endl;
}

int main(void)
{
    efficient;

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        solve();
    }
    return 0;
}
