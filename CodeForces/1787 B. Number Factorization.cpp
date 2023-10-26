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
#define showtwo(x, y)      cout << #x << " : " << x << " " << #y << " : " << y << endl
#define all(a)             a.begin(),a.end()
#define pb                 push_back
#define pf                 push_front
#define mp                 make_pair
#define ff                 first
#define ss                 second
#define input_arr(vec)     for(auto &&it:vec) {cin >> it;}
#define display_arr(vec)   for (auto &&it : vec){cout << it << " ";} cout << endl;
#define files              freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient()        ios_base::sync_with_stdio(0); cin.tie(0);
#define fraction()         cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return abs(a) * ( abs(b) / gcd ( a, b ) ); }

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);

/*---------------------------------------------------------------------------------------------------------------*/

bool cmp (const pii &a, const pii &b) {
    return a.second < b.second;
}

vi primeFactors(int n)  
{  
    vi primeF;
    while (n % 2 == 0)  {  
        primeF.push_back(2);
        n = n/2;  
    }  
    for (int i = 3; i <= sqrt(n + 1); i = i + 2)  
    {  
        while (n % i == 0) {  
            primeF.push_back(i);
            n = n/i;  
        }  
    }  
    if (n > 2) primeF.push_back(n);
    return primeF;
} 

void solve()
{
    int num; cin >> num;
    vi prime = primeFactors(num);
    
    vector<pii> primeCnt;
    int x = prime[0], cnt = 0;
    for (int i = 0; i < prime.size(); i++)
    {
        if (prime[i] == x) cnt++;
        else {
            primeCnt.push_back({prime[i - 1], cnt});
            x = prime[i];
            cnt = 1;
        }
    }
    primeCnt.push_back({prime[prime.size() - 1], cnt});
    sort(all(primeCnt), cmp);

    int n = primeCnt.size();
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll product = primeCnt[i].first;
        for (int j = i + 1; j < n; j++)
        {
            if (primeCnt[j].second != 0) {
                product *= (ll) primeCnt[j].first;
                primeCnt[j].second -= primeCnt[i].second;
            }
        }
        product *= primeCnt[i].second;
        ans += product;
    }
    
    cout << ans << endl;
}

int main(void)
{
    //efficient();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}
