class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        int count[30];
        memset(count, 0, sizeof(count));

        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
        }

        for (int i = 0; i < t.size(); i++) {
            if (count[t[i] - 'a'] > 0) count[t[i] - 'a']--;
            else return false;
        }

        return true;
    }
};