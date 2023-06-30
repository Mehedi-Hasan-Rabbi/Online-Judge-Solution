#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i=0; i<n; i++)
        cin >> arr[i];

    cout << arr[0];
    for (int i=2; i<n; i+=2)
        cout << ' ' << arr[i] ;

    cout << endl;
}

int main(void)
{
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

