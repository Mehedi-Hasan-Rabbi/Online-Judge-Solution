class Solution {
public:
    bool doesAliceWin(string s) {
        int vowel = 0;
        for (auto &u: s) {
            if (u == 'a' || u == 'e' || u == 'i' || u == 'o' || u == 'u')
                vowel++;
        }
        
        return vowel != 0;
    }
};