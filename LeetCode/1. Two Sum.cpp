// Solution 1 (Using two pointer approch)
// --------------------------------------
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < nums.size(); i++) 
            arr.push_back({nums[i], i});
        sort(arr.begin(), arr.end());

        int l = 0, r = nums.size() - 1;
        int x, y;
        while (l < r) {
            if (arr[l].first + arr[r].first == target) {
                x = arr[l].second;
                y = arr[r].second;
                break;
            }
            else if (arr[l].first + arr[r].first > target) r--;
            else l++;
        }
        return {x, y};
    }
};

// Solution 2 (Using hash)
// --------------------------------------
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
            freq[nums[i]] = i;
        
        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            if (freq.find(need) != freq.end() and freq[need] != i)
                return {i, freq[need]};
        }

        return {};
    }
};
