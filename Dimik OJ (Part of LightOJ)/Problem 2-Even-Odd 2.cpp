#include<bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    string number;

    cin >> t;

    while(t--)
    {
        cin >> number;

        int last_digit_asccii = (int) number[number.size()-1]; // Type casting from character to int returns ASCII value
        int last_digit = last_digit_asccii - 48; // ASCII value of 0-9 is 48-57

        if (last_digit >= 0 && last_digit <= 9)
        {
            if(last_digit%2 == 0)
                cout << "even" << endl;
            else
                cout << "odd" << endl;
        }
    }
    return 0;
}
