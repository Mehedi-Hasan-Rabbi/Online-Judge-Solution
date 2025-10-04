class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int empty = numBottles;
        numBottles = 0;

        while (empty >= numExchange) {
            empty -= numExchange;
            numExchange++;
            ans++;
            empty++;
        }

        return ans;
    }
};