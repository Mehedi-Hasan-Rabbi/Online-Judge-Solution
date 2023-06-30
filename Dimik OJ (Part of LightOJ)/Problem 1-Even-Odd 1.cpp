#include<iostream>
using namespace std;
int main(void)
{
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if (n%2 == 0)
            cout << "even" << endl;
        else
            cout << "odd" << endl;
    }
    return 0;
}
