#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n;
    cin >> n;
    if(n == 2) {
        cout << "1 2" << '\n';
        return;
    }
    for(int i = 1; i <= n; i+= 2) cout << i << ' ';
    for(int i = 2; i <= n; i+= 2) cout << i << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int C = 1; C <= T; C++) {
        // cout << "Case " << C << ": " << '\n';
        idea();
    }
    return 0;
}