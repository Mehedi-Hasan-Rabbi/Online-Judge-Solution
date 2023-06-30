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

    string line;
    int upper = 0, lower = 0;
    cin >> line;

    for (int i=0; i<line.size(); i++)
    {
        if (isupper(line[i]))
            upper++;
        else
            lower++;
    }
    if((lower > upper) || (lower == upper))
    {
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        cout << line << '\n';
    }
    else if(lower < upper)
    {
        transform(line.begin(), line.end(), line.begin(), ::toupper);
        cout << line << '\n';
    }
    return 0;
}

