class Solution {
public:
    string sortVowels(string s) {
        int n = (int) s.size();
        vector<int> up(26, 0), down(26, 0);
        for (auto &ch: s) {
            if ('A' <= ch and ch <= 'Z') {
                up[ch - 'A']++;
                if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
                    ch = '#';
            }
            else {
                down[ch - 'a']++;
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                    ch = '#';
            }
        }

        // Vowel index
        vector<int> idx = {0, 4, 8, 14, 20};
        for (int i = 0; i < n; i++) {
            // Try to fill with uppercase
            if (s[i] == '#') {
                for (int j = 0; j < 5; j++) {
                    if (up[idx[j]] > 0) {
                        s[i] = 'A' + idx[j];
                        up[idx[j]]--;
                        break;
                    }
                }
            }
            // If run out of uppercase then use lowercase
            if (s[i] == '#') {
                for (int j = 0; j < 5; j++) {
                    if (down[idx[j]] > 0) {
                        s[i] = 'a' + idx[j];
                        down[idx[j]]--;
                        break;
                    }
                }
            }
        }

        return s;
    }
};