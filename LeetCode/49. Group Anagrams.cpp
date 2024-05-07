// Solution 1 (My Solution)
// --------------------------------------------------------
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<pair<string, vector<int>>> count;

        for (int i = 0; i < strs.size(); i++) 
        {
            string s = strs[i];
            vector<int> freq(26, 0);
            for (int i = 0; i < s.size(); i++)
                freq[s[i] - 'a']++;
            count.push_back( {s, freq} );
        }

        vector<bool> visited(strs.size(), false);
        for (int i = 0; i < strs.size(); i++)
        {
            vector<string> group;
            if (visited[i] == false) 
            {
                visited[i] = true;
                group.push_back(count[i].first);
                for (int j = i + 1; j < strs.size(); j++)
                {
                    if (count[i].second == count[j].second) 
                    {
                        group.push_back(count[j].first);
                        visited[j] = true;
                    }
                }
            }

            if (group.size() > 0) ans.push_back(group);
        }

        return ans;
    }
};


// Solution 2 (Simpler)
// --------------------------------------------------------
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>> mp;

        for (auto x: strs)
        {
            string s = x;
            sort(s.begin(), s.end());
            mp[s].push_back(x);
        }

        for (auto [str, vec]: mp)
            ans.push_back(vec);
        
        return ans;
    }
};