#include<bits/stdc++.h>

using namespace std;

int main(void)
{
    string str;
    cin >> str;

    int distinct = 0, flag = 0;
    for (int i=0; i<str.length(); i++)
    {
        flag = 0;
        for (int j=i+1; j<str.length(); j++)
        {
            if(str[i] == str[j])
            {
                flag = 1;
            }
        }
        if (flag == 0 )
        {
            distinct++;
        }
    }


    if(distinct%2 == 0)
        cout << "CHAT WITH HER!" << endl;

    else
        cout << "IGNORE HIM!" << endl;
    return 0;
}
