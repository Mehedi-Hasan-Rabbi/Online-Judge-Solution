#include <bits/stdc++.h>
using namespace std;

bool isVowel (char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

int main() 
{
    string s, ans; 
    cin >> s;

    for (auto &&i : s)
    {
        char c = tolower(i);

        if (!isVowel(c)) {
            ans += '.';
            ans += c;
        }
    }
    
    cout << ans << endl;

    return 0;
}