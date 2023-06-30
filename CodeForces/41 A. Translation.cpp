#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s, t;
	getline(cin, s);
	getline(cin, t);

	reverse(s.begin(), s.end());

	if(s == t)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
	return 0;
}
