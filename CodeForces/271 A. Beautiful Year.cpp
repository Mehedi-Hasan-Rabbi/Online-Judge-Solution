#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define show(x) cout << #x << " : " << x << endl
#define files freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient ios::sync_with_stdio(0); cin.tie(0);


ll check_unique(ll num)
{
    string s = to_string(num);

    set<ll> uniDigits(s.begin(), s.end());

    if (s.size() == uniDigits.size())
    {
        cout << num << '\n';
        return 0;
    }

}

int main(void)
{
    efficient;

    ll year, distinct_year;
    cin >> year;

    while(true)
    {
        year++;
        ll res = check_unique(year);
        if (res == 0)
            return 0;
    }
    return 0;
}

