class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = (int) nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                int cnt_zero = 0;
                for (int j = i + 1; j < n; j++) {
                    if (nums[j] == 0) cnt_zero++;
                    else {
                        if (cnt_zero >= k) {
                            cnt_zero = 0;
                            i = j - 1;
                            break;
                        }
                        else return false;
                    }
                }
            }
        }

        return true;
    }
};