// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define endl         '\n'
#define yes          cout << "Yes" << endl
#define no           cout << "No" << endl
#define show(x)      cout << #x << " : " << x << endl
#define files        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient    ios::sync_with_stdio(0); cin.tie(0);

void solve()
{
    int n;
    cin >> n;
    int arr[n+1], A[n+1];

    for (int i=1; i<=n; i++)
    {
        cin >> arr[i];
        A[i] = i;
    }

    if (n==1)
    {
        cout << "-1" << endl;
        return;
    }
    for (int i=1; i<n; i++)
    {
        if (A[i] == arr[i])
            swap(A[i], A[i+1]);
    }
    if(A[n] == arr[n])
        swap(A[n], A[n-1]);

    for (int i=1; i<=n; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main(void)
{
    efficient;

    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

