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

    string dna;
    cin >> dna;

    int max_rep = 0, rep = 0, len=dna.size();
    char ch = dna[0];

    for (int i=0; i<len; i++)
    {
        if(dna[i] == ch)
        {
            rep++;
        }
        else
        {
            if(rep>max_rep)
                max_rep=rep;
            ch = dna[i];
            rep = 1;
        }
    }
    if(rep>max_rep)
        max_rep=rep;

    cout << max_rep << '\n';

    return 0;
}

