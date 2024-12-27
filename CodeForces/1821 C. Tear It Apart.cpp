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
 
const ll mod = 1e9 + 7; // 1000000007;
const double PI = acos(-1);
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}
 
/*---------------------------------------------------------------------------------------------------------------*/
 
void solve()
{
    string s;
    cin >> s;
    ll n = s.size(), c = 0, mini = INT_MAX, maxi;
    for(char i = 'a'; i <= 'z' ; i++) {
        c = 0, maxi = 0;
        for(ll j = 0 ; j < n ; j++) {
            if(s[j] != i) {
                c++;
                if(c > maxi)
                    maxi = c;
            }
            else { 
                c = 0;
            }
        }
        
        if(maxi < mini) {
            mini = maxi;
        }
        
    }
    
    if(mini == 0)
        cout << 0 <<endl;
    else {
        c = 0;
        while(mini != 1) {
            mini /= 2;
            c++;
        }
        cout << c + mini <<endl;
    }
}
 
int main(void) {
    efficient();
 
    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
 
    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}