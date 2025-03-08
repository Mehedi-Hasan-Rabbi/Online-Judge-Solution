class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        int l = 0, r = k - 1;
        int white = 0, black = 0;

        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'B') black++;
            else white++;
        }

        int ans = white;
        while (r < (int) blocks.size()) {
            if (blocks[l] == 'B') black--;
            else white--;
            l++, r++;
            if (blocks[r] == 'B') black++;
            else white++;
            
            ans = min(white, ans);
        }

        return ans;
    }
};