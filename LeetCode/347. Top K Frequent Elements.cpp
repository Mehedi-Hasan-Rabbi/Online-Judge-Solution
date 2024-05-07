class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        vector<pair<int, int>> arr;
        vector<int> ans;

        for (auto u: nums) freq[u]++;
        for (auto [val, cnt]: freq)
            arr.push_back({cnt, val});
        
        sort(arr.begin(), arr.end(), greater<pair<int, int>>());

        for (int i = 0; i < k; i++)
            ans.push_back(arr[i].second);

        return ans;
    }
};