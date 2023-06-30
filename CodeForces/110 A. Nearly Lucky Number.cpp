#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define show(x) cout << #x << " : " << x << endl
#define files freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient ios::sync_with_stdio(0); cin.tie(0);


int main(void)
{
    efficient;

    ll number;
    int kount = 0;

    cin >> number;

    while(number!=0)
    {
        if (number%10 == 7 || number%10 == 4)
            kount++;
        number = number/10;
    }

    if (kount == 4 || kount == 7)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
    return 0;
}

