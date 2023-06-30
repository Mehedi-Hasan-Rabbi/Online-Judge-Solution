#include<bits/stdc++.h>
using namespace std;

int two = 0, five = 0;

void factorization(int n) // In bangla 'উৎপাদ = Factorization'
{

    vector<int> v;

    for (int i=2; i<=n; )
    {
        if(n%i == 0)
        {
            n = n/i;
            v.push_back(i);
            if (i == 2)
                two = two + 1;
            else if(i == 5)
                five = five + 1;
            i = 2;
        }
        else
            i++;
    }
    //for (int i=0; i<v.size(); i++)
    //    cout << v[i] << ' ';
    //cout << endl;
}

int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        for (int i=2; i<=n; i++)
            factorization(i);
        //cout << "Two: " << two << ' ' << "Five: " << five << endl;

        if (two < five)
        {
            cout << two << endl;
            two = 0;
        }
        else
        {
            cout << five << endl;
            five = 0;
        }
        two = 0;
        five = 0;
    }
    return 0;
}

