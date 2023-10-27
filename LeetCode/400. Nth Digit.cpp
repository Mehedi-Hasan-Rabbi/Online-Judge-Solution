class Solution {
public:
    int findNthDigit(int n) {
        long long num = (long long) n;
        if (n <= 9) return n;

        long long val = 9, val_digit = 1;
        while (n - (val * val_digit) >= 0LL)
        {
            n = n - (val * val_digit);
            val = val * 10;
            val_digit++;
        }
        
        long long start = val / 9LL;
        start = start + (n / val_digit);

        if (n % val_digit == 0LL) {
            start--;
            return start % 10LL;
        }
        else {
            int id = n % val_digit;
            string num = to_string(start);
            return num[id - 1] - '0';
        }
    }
};