#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define show(x) cout << #x << " : " << x << endl
#define files freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient ios::sync_with_stdio(0); cin.tie(0);


int main(void)
{
    efficient;

    int length, counter=0;
    cin >> length;

    char s[length];
    cin >> s;

    char target = s[0];
    for (int i=0; i<length; i++)
    {
        if (target == s[i+1])
        {
            counter++;
            target = s[i+1];
        }
        else
            target = s[i+1];
    }
    cout << counter << '\n';
    return 0;
}

