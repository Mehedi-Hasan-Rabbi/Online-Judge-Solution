class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        string sum = "";

        int i = 0, j = 0, c = 0;
        while (true) {
            int a = 0, b = 0;

            if (i < (int) num1.size()) a = num1[i] - '0', i++;
            if (j < (int) num2.size()) b = num2[j] - '0', j++;

            int s = (a + b + c) % 10;
            c = (a + b + c) / 10;

            sum.push_back( s + '0' );

            if (i == (int) num1.size() and j == (int) num2.size() and c == 0)
                break;
        }

        reverse(sum.begin(), sum.end());
        return sum;
    }
};