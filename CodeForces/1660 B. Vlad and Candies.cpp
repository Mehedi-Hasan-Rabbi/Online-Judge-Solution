#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main(void)
{
    ll t;
    cin >> t;

    while(t--)
    {
        ll type;
        cin >> type;

        ll arr[type];

        for (ll i=0; i<type; i++)
            cin >> arr[i];

        ll n = sizeof(arr) / sizeof(arr[0]);

        if (type == 1)
        {
            if (arr[0] > 1)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;

            continue;
        }

        sort(arr, arr + n);


        if (arr[n-1] - arr[n-2] > 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;


    }
    return 0;
}
