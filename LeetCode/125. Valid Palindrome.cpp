class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for (auto u: s) {
            if ('a' <= u and u <= 'z') str.push_back(u);
            else if ('A' <= u and u <= 'Z') str.push_back(u + 32);
            else if ('0' <= u and u <= '9') str.push_back(u);
        }
        
        int l = 0, r = str.size() - 1;
        while (l <= r) {
            if (str[l] != str[r]) return false;
            l++, r--;
        }
        return true;
    }
};