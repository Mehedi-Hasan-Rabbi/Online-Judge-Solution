class Solution {
public:
    string add(string s1, string s2) {
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        string sum = "";

        int i = 0, j = 0, c = 0;
        while (true) {
            int a = 0, b = 0;

            if (i < (int) s1.size()) a = s1[i] - '0', i++;
            if (j < (int) s2.size()) b = s2[j] - '0', j++;

            int s = (a + b + c) % 10;
            c = (a + b + c) / 10;

            sum.push_back( s + '0' );

            if (i == (int) s1.size() and j == (int) s2.size() and c == 0)
                break;
        }

        reverse(sum.begin(), sum.end());
        return sum;
    }
};