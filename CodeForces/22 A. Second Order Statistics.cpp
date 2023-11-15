// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define endl               '\n'
#define efficient()        ios_base::sync_with_stdio(0); cin.tie(0);
#define fraction()         cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

/*---------------------------------------------------------------------------------------------------------------*/

int main(void)
{
    efficient();

    set<int> s;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        s.insert(x);
    }
    
    if (s.size() == 1) cout << "NO" << endl;
    else {
        cout << *(++s.begin()) << endl;
    } 

    return 0;
}
