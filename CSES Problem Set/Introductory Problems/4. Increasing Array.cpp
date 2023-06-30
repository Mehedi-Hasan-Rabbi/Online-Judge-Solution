#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define show(x) cout << #x << " : " << x << endl
int main(void)
{
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++)
        cin >> arr[i];

    ll min_mov=0, mov = 0;

    for(ll i=1; i<n; i++)
    {
        if(arr[i]<arr[i-1])
        {
            mov = abs(arr[i] - arr[i-1]);
            min_mov+=mov;
            arr[i]+=mov;
        }

    }

    cout << min_mov << '\n';
    return 0;
}
