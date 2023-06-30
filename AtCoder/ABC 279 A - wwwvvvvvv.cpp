#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int ans = 0;
    for (int i=0; i<s.size(); i++)
    {
        if(s[i] == 'w')
            ans = ans + 2;
        else
            ans++;
    }
    cout << ans << endl;

    return 0;
}