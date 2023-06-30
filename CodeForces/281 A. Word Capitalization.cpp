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

    string line;
    cin >> line;

    if (isupper(line[0]))
    {
        cout << line << '\n';
    }
    else
    {
        line[0] = line[0] - 32;
        cout << line << '\n';
    }


    return 0;
}

