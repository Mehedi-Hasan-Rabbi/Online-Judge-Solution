#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int isDigitSumPalindrome(int N) {
        int digitSum = 0;

        while (N != 0)
        {
            digitSum += N % 10;
            N /= 10;
        }
        
        string s = to_string(digitSum);
        string tmp = s;

        reverse(tmp.begin(), tmp.end());

        if (s == tmp) return 1;
        else return 0;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isDigitSumPalindrome(N) << "\n";
    }
}
