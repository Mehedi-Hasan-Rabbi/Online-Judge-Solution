class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;
        for (int i = 0; i < mainTank; i++)
        {
            if (mainTank%5 == 0 and additionalTank != 0) {
                mainTank++;
                additionalTank--;
            }
            ans += 10;
        }
        return ans;
    }
};