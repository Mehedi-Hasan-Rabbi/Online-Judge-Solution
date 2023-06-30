#include<bits/stdc++.h>
using namespace std;

int acending(int *arr, int *n)
{
    int sorted = 1;
    for (int i=1; i<*n; i++)
    {
        if(arr[i] < arr[i-1])
        {
            sorted = 0;
            break;
        }
    }
    return sorted;
}

int descending(int *arr, int *n)
{
    int sorted = 1;
    for (int i=1; i<*n; i++)
    {
        if(arr[i] > arr[i-1])
        {
            sorted = 0;
            break;
        }
    }
    return sorted;
}

void solve()
{
    int n;
    cin>>n;

    int arr[n];

    for (int i=0; i<n; i++)
        cin >> arr[i];

    int asc = acending(arr, &n);
    int des = descending(arr, &n);

    if(asc==1)
        cout << "YES" << endl;
    else if(des==1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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

