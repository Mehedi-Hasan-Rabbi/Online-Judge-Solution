#include<bits/stdc++.h>
using namespace std;

#define size 100001
int ara[size];

void SieveOfEratosthenes()
{
    int i, j, root;
    for (i=2; i<size; i++)
        ara[i] = 1;

    root = sqrt(size);
    for(i=2; i<=root; i++)
    {
        if(ara[i]==1)
        {
            for(j=2; i*j<=size; j++)
                ara[i*j] = 0;
        }
    }
}

int main(void)
{
    int t, a, b, count;
    SieveOfEratosthenes();

    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        count = 0;

        for (int i=a; i<=b; i++)
        {
            if (ara[i])
                count++;
        }
        cout << count << '\n';
    }
}
