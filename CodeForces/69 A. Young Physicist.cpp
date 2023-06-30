#include<iostream>
using namespace std;

int main ()
{
    int n, a, b, c, d=0, e=0, f=0;
    cin >> n;
    while (n--)
    {
        cin >> a >> b >> c;
        d += a;
        e += b;
        f += c;
    }
    cout << (d | e | f ? "NO" : "YES");
}
