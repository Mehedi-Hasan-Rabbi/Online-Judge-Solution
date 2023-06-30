#include<bits/stdc++.h>

using namespace std;


solve()
{
    int n, d;
    cin >> n >> d;

    int arr[n];
    for (int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    if (arr[n-1] <= d)
        cout << "YES" << endl;

    else
    {
        for (int i=n-1; i>=0; i--)
        {
            if(arr[i] <=d )
            {
                cout << "YES" << endl;
                return 0;
            }

            else
            {
                for (int j=0; j<n; j++)
                {
                    int check = arr[j] + arr[j+1];
                    if (check <= d)
                    {
                        arr[i] = check;
                        break;
                    }
                    else
                    {
                        cout << "NO" << endl;
                        return 0;
                    }
                }
            }
        }
    }
}


int main(void)
{
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }
    return 0;
}
