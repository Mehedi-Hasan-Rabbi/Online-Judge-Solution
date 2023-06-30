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

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        string name, base;
        cin >> name;
        base = "Timur";

        sort(base.begin(), base.end());

        if (n>5 && n<5)
            cout << "NO" << '\n';
        else
        {
            sort(name.begin(), name.end());
            if(name == base)
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }
    return 0;
}

