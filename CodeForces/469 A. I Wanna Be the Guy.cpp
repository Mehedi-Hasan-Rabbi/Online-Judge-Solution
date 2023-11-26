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

    int p; cin >> p;
    for (int i = 0; i < p; i++)
    {
        int x; cin >> x;
        s.insert(x);
    }
    
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        int x; cin >> x;
        s.insert(x);
    }
    
    if (s.size() == n) cout << "I become the guy." << endl;
    else cout << "Oh, my keyboard!" << endl;

    return 0;
}
