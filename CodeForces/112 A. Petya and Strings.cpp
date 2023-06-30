#include<bits/stdc++.h>

using namespace std;

int main(void)
{
    string str1, str2;
    cin >> str1 >> str2;

    int res;

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    for(int i=0; i<str1.length(); i++)
    {
        if (str1[i] > str2[i])
        {
            res = 1;
            break;
        }
        else if (str1[i] < str2[i])
        {
            res = -1;
            break;
        }
        else
            res = 0;
    }

    cout << res << endl;
    return 0;
}
