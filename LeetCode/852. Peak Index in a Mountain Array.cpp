class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i = max_element(arr.begin(), arr.end()) - arr.begin();
        return i;
    }
};