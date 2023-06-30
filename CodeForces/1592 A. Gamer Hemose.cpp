#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll num_wep, health;
    cin >> num_wep >> health;

    ll power[num_wep];

    for (ll i=0; i<num_wep; i++)
    {
        cin >> power[i];
    }

    sort(power, power+num_wep, greater<ll>());

    ll sum_pow = power[0] + power[1];

    if(power[0] >= health)
        cout << '1' << '\n';
    else if(sum_pow >= health)
        cout << '2' << '\n';
    else
    {
        if(health%sum_pow == 0)
            cout << (health/sum_pow)*2 << '\n';
        else if(health%sum_pow <= power[0])
            cout << (health/sum_pow)*2+1 << '\n';
        else
            cout << (health/sum_pow)*2+2 << '\n';
    }

}

int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
