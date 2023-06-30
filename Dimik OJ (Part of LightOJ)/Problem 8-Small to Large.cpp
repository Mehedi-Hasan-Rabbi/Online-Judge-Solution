#include<bits/stdc++.h>
using namespace std;

void swaping(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int main(void)
{
    int t;
    cin >> t;

    for (int i=1; i<=t; i++)
    {
        int n1, n2, n3, temp;
        cin >> n1 >> n2 >> n3;

        if(n1 > n2)
        {
            swaping(&n1, &n2);
        }

        if(n2 > n3)
        {
            swaping(&n2, &n3);
        }

        if(n1 > n2)
        {
            swaping(&n1, &n2);
        }

        cout << "Case " << i << ": " << n1 << ' ' << n2 << ' ' << n3 << endl;
    }
    return 0;
}
