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
#define display_arr(vec)   for (auto &&it : vec){cout << it << " ";} cout << endl;
#define files              freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient          ios_base::sync_with_stdio(0); cin.tie(0);

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    string s;
    cin >> s;

    for (int i = 1; i < s.size() / 2; i++)
    {
        if (s[0] != s[i]){
            yes; return;
        }
    }
    no;

    // Alternate Solution is given below
}

int main(void)
{
    efficient;

    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

// void solve()
// {
//     string s;
//     cin >> s;
//     int len = s.size() / 2;
//     string st;
//     int cnt = 0;
//     for (int i = 0; i < len; i++)
//         st.push_back(s[i]);
//     s = st;
//     for (int i = 0; i < len; i++)
//     {
//         for (int j = i+1; j < len; j++)
//         {
//             string t = st;
//             swap(t[i], t[j]);
//             if (t != s){
//                 cnt=1; break;
//             }
//         }
//         if (cnt == 1) break;       
//     }
//     if (cnt) yes;
//     else no;  
// }
