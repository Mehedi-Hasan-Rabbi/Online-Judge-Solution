#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int arr[n-1];

    for (int i=0; i<n-1; i++)
        cin >> arr[i];

    sort(arr, arr + n-1);

    for (int i=1; i<=n; i++)
    {
        if(!binary_search(arr, arr + n - 1 , i))
            cout << i << '\n';
    }

}

// Another Way to solve this problem
// 1+2+3+.....+n = n * (n + 1) ) / 2
// property of the natural numbers
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n, input, sum = 0;
    cin >> n;

    for (int i = 0 ; i < n - 1 ; i++) {
        cin >> input;
        sum += input;
    }

    cout << ( n * (n + 1) ) / 2 - sum << endl;

    return 0;
}
*/
