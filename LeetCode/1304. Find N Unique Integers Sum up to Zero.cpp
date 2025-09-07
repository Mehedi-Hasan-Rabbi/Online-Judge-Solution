class Solution {
public:
    vector<int> sumZero(int n) {
        if (n == 1)
            return {0};
        if (n == 2)
            return {-1, 1};
        if (n == 3)
            return {-1, 0, 1};

        vector<int> a(n, 0);

        if (n % 2 == 1) {
            a[0] = -1, a[1] = 0, a[2] = 1;
            for (int i = 3; i < n; i += 2) 
                a[i] = i, a[i + 1] = (i * -1);
        }
        else {
            for (int i = 0; i < n; i += 2) 
                a[i] = i + 1, a[i + 1] = ((i + 1) * -1);
        }
        
        return a;
    }
};