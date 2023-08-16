// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define endl               '\n'
#define yes                cout << "YES" << endl
#define no                 cout << "NO" << endl
#define show(x)            cout << #x << " : " << x << endl
#define all(a)             a.begin(),a.end()
#define pb                 push_back
#define pf                 push_front
#define mp                 make_pair
#define ff                 first
#define ss                 second
#define input_arr(vec)     for(auto &&it:vec) {cin >> it;}
#define display_arr(vec)   for (auto &&it : vec){cout << it << " ";} cout << endl;
#define files              freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient          ios_base::sync_with_stdio(0); cin.tie(0);

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);

/*---------------------------------------------------------------------------------------------------------------*/

bool areBracketsBalanced(string expr) // Copied from GeeksForGeeks
{
    stack<char> temp;
    for (int i = 0; i < expr.length(); i++) {
        if (temp.empty()) {
            temp.push(expr[i]);
        }
        else if ((temp.top() == '(' && expr[i] == ')')
                 || (temp.top() == '{' && expr[i] == '}')
                 || (temp.top() == '[' && expr[i] == ']')) {
            temp.pop();
        }
        else {
            temp.push(expr[i]);
        }
    }
    if (temp.empty()) {
        return true;
    }
    return false;
}

void solve()
{
    string s; cin >> s;
    int sz = s.size();
    if (s[0] == s[sz - 1]) {
        no;
        return;
    }

    char first = s[0];
    char last = s[sz - 1];

    string test = "";
    for (int i = 0; i < sz; i++)
    {
        if (s[i] == first) test.push_back('(');
        else if (s[i] == last) test.push_back(')');
        else test.push_back('(');
    }
    
    bool ok = areBracketsBalanced(test);

    if (ok) {
        yes;
        return;
    }

    test = "";
    for (int i = 0; i < sz; i++)
    {
        if (s[i] == first) test.push_back('(');
        else if (s[i] == last) test.push_back(')');
        else test.push_back(')');
    }

    ok = areBracketsBalanced(test);

    if (ok) yes;
    else no;
}

int main(void)
{
    efficient;

    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
