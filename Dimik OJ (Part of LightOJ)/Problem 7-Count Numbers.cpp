//Problem Solution in c provided in 52 programming problem and solution book
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

void solve()
{
    char line[100000];
    scanf(" %[^\n]", line);
    char *p, *e;
    long input;
    int count = 0;
    //p = line;

    //cout << p << '\n';
    for (p = line; ; p = e)
    {
        input = strtol(p, &e, 10); // string to long converter. Goto http://www.cplusplus.com/reference/cstdlib/strtol/
        //cout << input << '\n';
        //cout << p << '\n';
        if (p == e)
        {
            break;
        }
        count++;
    }
    printf("%d\n", count);
}

int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}

/*#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    char space;
    cin >> space;
    while (t--)
    {
        string numbers;
        getline(cin, numbers);
        int counter = 0;
        for (int i=0; i<numbers.size(); i++)
        {
            if(numbers[i] == ' ')
                counter++;
        }
        cout << counter+1 << endl;
    }
    return 0;
}
*/
