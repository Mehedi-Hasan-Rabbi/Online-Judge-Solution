#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    getline(cin, str);

    vector<int> v;
    int x;

    for (int i=0; i<str.size(); i++)
    {
        if(str[i] != '+')

            x = (int)(str[i]); // ASCII code insert in x of every char of str[i]
            v.push_back(x);
        }
    }

    sort(v.begin(), v.end());

    for (int i=0; i<v.size(); i++)
    {
        cout << (char) (v[i]);
        if(i<v.size()-1)
            cout << "+";
    }
    return 0;
}
