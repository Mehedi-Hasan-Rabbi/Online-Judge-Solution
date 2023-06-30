#include<bits/stdc++.h>

using namespace std;

int main(void)
{
    string str;
    getline (cin, str);


    int flag = 0;
    for(int i=0; i<str.size(); i++)
    {
        flag = 0;
        switch(str[i])
        {
        case 'H':
        case 'Q':
        case '9':
            cout << "YES" << endl;
            flag = 1;
            break;
        }
        if(flag == 1)
            break;
    }
    if(flag == 0)
        cout << "NO" << endl;
    return 0;
}
