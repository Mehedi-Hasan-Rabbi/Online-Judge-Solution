class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> brok(26, 0);
        for (auto &ch: brokenLetters)
            brok[ch - 'a'] = true;
        
        text += " ";
        int ans = 0;
        bool possible = true;
        for (auto &ch: text) {
            if (ch == ' ') {
                ans += ((possible == true) ? 1 : 0);
                possible = true;
                continue;
            }

            if (brok[ch - 'a']) possible = false;
        }

        return ans;
    }
};