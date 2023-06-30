#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int char_len, second;
    cin >> char_len >> second;

    char line[char_len];
    for (int i=0; i<char_len; i++)
        cin >> line[i];

    for (int i=1; i<=second; i++)
    {
        int index = 0;
        while (index <= char_len-1)
        {
            if(line[index]=='B' && line[index+1]=='G')
            {
                swap(line[index], line[index+1]);
                index = index + 2;
            }
            else
                index++;
        }

    }
    for (int i=0; i<char_len; i++)
            cout << line[i];
    cout << '\n';
    return 0;
}
