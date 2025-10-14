class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = (int) words.size();

        vector<string> ans;
        for (int i = 0; i < n; i++) {
            string x = words[i];
            ans.push_back(x);
            sort(x.begin(), x.end());

            for (int j = i + 1; j < n; j++) {
                string y = words[j];
                sort(y.begin(), y.end());
                
                if (x == y) {i = j; continue;}
                else break;
            }
        }
        
        return ans;
    }
};