// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pi;

#define endl         '\n'
#define yes          cout << "Yes" << endl
#define no           cout << "No" << endl
#define show(x)      cout << #x << " : " << x << endl
#define files        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient    ios_base::sync_with_stdio(0); cin.tie(0);

const ll MOD = 1e9 + 7; // 1000000007;

/*---------------------------------------------------------------------------------------------------------------*/

void solve_2()
{
    int n; cin >> n;
    int arr[300];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int m; cin >> m;
    for (int i = n; i < n+m; i++)
        cin >> arr[i];

    sort(arr, arr+n+m);

    for (int i = 0; i < n+m; i++)
        cout << arr[i] << " ";
    cout << endl;  
}

void solve()
{ 
    int n1; cin >> n1;
    int arr1[n1];
    for (int i = 0; i < n1; i++)
        cin >> arr1[i]; 

    int n2; cin >> n2;
    int arr2[n2];
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];

    int i = 0, j = 0, k = 0, n;
    int ans[n1+n2];

    while ((i != n1) && (j != n2))
    {
        if (arr1[i] < arr2[j])
        {
            ans[k] = arr1[i];
            i++; k++;
        }
        else
        {
            ans[k] = arr2[j];
            j++; k++;
        }
    }
    if (i == n1)
    {
        while(j!=n2)
        {
            ans[k] = arr2[j];
            k++; j++;
        }    
    }

    else
    {
        while(i != n1)
        {
            ans[k] = arr1[i];
            k++; i++;
        }  
    }
    n = k;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
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
