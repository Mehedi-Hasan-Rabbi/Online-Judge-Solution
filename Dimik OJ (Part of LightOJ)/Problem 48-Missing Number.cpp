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

void solve_1()  // This method is not efficient
{
    int n, found;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 1; i <= n; i++)
    {
        found  = 0;
        for (int j = 0; j < n-1; j++)
        {
            if (i == arr[j])
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            cout << "Missing number: " << i << endl;
            break;
        }
    }   
}

void solve_2()  // This method is better than solve_1()
{
    int ara[100001];
    int n, num, missing;
    cin >> n;

    for (int i = 1; i <= n; i++) 
        ara[i] = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        ara[num] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (ara[i] == 0)
        {
            missing = i;
            break;
        }
    }
    
    cout << "Missing number: " << missing << endl;
    
}

void solve()
{
    int n, input, sum = 0;
    cin >> n;
 
    for (int i = 0 ; i < n - 1 ; i++) {
        cin >> input;
        sum += input;
    }
 
    cout << ( n * (n + 1) ) / 2 - sum << endl;
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
