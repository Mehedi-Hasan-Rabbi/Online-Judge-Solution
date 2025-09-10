class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();

        // Which users know which language.
        vector<set<int>> knowLang(m + 1);
        for (int i = 0; i < m; i++) {
            for (auto u: languages[i])
                knowLang[i + 1].insert(u);
        }

        // Find those user who can't communicate with each other.
        set<int> badUser;
        for (auto frd: friendships) {
            int u = frd[0];
            int v = frd[1];

            bool communicate = false;
            // If u can't communicate with v then one need to learn a new language.
            for (auto lang: knowLang[u]) {
                if (knowLang[v].count(lang) == 1) {
                    communicate = true;
                }
            }

            if (!communicate)
                badUser.insert(u), badUser.insert(v);
        }

        if (badUser.size() == 0) return 0;

        // Which language is best to learn
        int ans = INT32_MAX;
        for (int lang = 1; lang <= n; lang++) {
            int teach = 0;
            for (auto u: badUser) {
                if (knowLang[u].count(lang) == 0)
                    teach++;
            }

            ans = min(ans, teach);
        }

        return ans;
    }
    // unordered_set can also be used in this problem
};