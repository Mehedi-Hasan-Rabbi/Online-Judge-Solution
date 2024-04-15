class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++) {
            int val = target - numbers[i];
            int lower = lower_bound(numbers.begin()+i+1, numbers.end(), val) - numbers.begin();

            if (lower < numbers.size() && numbers[lower] == val)
                return { i + 1, lower + 1 };
        }

        return { -1, -1 };
    }
};