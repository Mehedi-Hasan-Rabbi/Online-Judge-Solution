#include <iostream>
using namespace std;

void solve()
{
    int x, y;
    cin >> x >> y;
    if (x>y)
        cout << ">" << endl;
    else if (x<y)
        cout << "<" << endl;
    else
        cout << "=" << endl;
}

int main() {
	int t; cin >> t;
	while(t--)
	{
	    solve();
	}
	return 0;
}
