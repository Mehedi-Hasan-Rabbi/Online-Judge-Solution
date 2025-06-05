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
 
int gcd ( int a, int b ) { return __gcd ( a, b ); }
int lcm ( int a, int b ) { return abs(a) * ( abs(b) / gcd ( a, b ) ); }
 
int dx[] = {+1, -1, 0, 0, +1, +1, -1, -1};
int dy[] = {0, 0, -1, +1, +1, -1, +1, -1};
 
const ll mod = 1e9 + 7; // 1000000007;
const double PI = 3.14159265358979323846;
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}
 
/*---------------------------------------------------------------------------------------------------------------*/
 
void solve()
{
    int n; cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    // Final array's all element will always be GCD of the whole array.
    int tot_GCD = a[0];
    for (int i = 0; i < n; i++)
        tot_GCD = gcd(tot_GCD, a[i]);
    
    // Check if a number is equal to tot_GCD
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == tot_GCD)
            found = true;
    }

    if (found) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if ( a[i] != tot_GCD)
                ans++;
        }
        cout << ans << endl; 
        return; 
    }
    
    // If there aren't any number which is equal to tot_GCD then we need to find a minimum subsequence which GCD is equal to tot_GCD
    
    // See to below Editorial

    vector<int> move(5005, INT32_MAX);
    queue<int> q;

    for (int i = 0; i < n; i++)
        move[a[i]] = 0, q.push(a[i]);

    int min_move = INT32_MAX;
    while (!q.empty()) {
        int val = q.front();
        q.pop();

        for (auto u: a) {
            int curr = gcd(val, u);

            if ((move[curr] == INT32_MAX) or (move[curr] > move[val] + 1)) {
                move[curr] = move[val] + 1;

                q.push(curr);
            }

        }
    }

    cout << n - 1 + move[tot_GCD] << endl;

    // Time: O(n*a_i*log(a_i)) --> log(a_i) is for GCD;
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

/*
    Editorial
    ------------------------------------------------------------------------
    To find this we can use Multisource BFS. How?
    example: a = {6, 10, 15, 30}

    Root Source: move[x] = How many move do we need to make x,
    move[6] = 0; Since 6 is already in the array we can make it in 0 move
    move[10] = 0; Since 10 is already in the array we can make it in 0 move
    move[15] = 0; Since 15 is already in the array we can make it in 0 move
    move[30] = 0; Since 30 is already in the array we can make it in 0 move

    queue = {6, 10, 15, 30}
    Now, int val = q.front(); val = 6
    and, Find GCD(val, a[i]) and push it to queue
    
    GCD(6, 6) = 6;
    GCD(6, 10) = 2; Now, move[2] = move[6] + 1 --> So, to make 2 we need (6, 10). And to make 6 we need 0 operation and 10 is used right now.
    GCD(6, 15) = 3:; Now, move[3] = move[6] + 1 --> So, to make 3 we need (6, 15). And to make 6 we need 0 operation and 15 is used right now.

    And each time puch them into the queue. And remember to update move[x] with minimum move
    
    */