class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        string ans = "";
        if (numerator < 0 and denominator > 0) {
            numerator = numerator * -1;
            ans += "-";
        }
        else if (numerator > 0 and denominator < 0) {
            denominator = denominator * -1;
            ans += "-";
        }
        else if (numerator < 0 and denominator < 0) {
            numerator = numerator * -1;
            denominator = denominator * -1;
        }
        
        long long divisor = denominator;
        long long dividend = numerator;
        map<long long, int> rem;

        // Before Decimal Point
        long long quotient = (dividend / divisor);
        long long remainder = (dividend % divisor);
        
        ans += to_string(quotient);
        if (remainder == 0)
        return ans;
        
        // After Decimal Point
        ans += ".";
        dividend = remainder;
        rem[remainder] = ans.size();
        bool duplicate = false;

        while (dividend != 0 and ans.size() < 1e4) {
            dividend = dividend * 10;
            
            while (dividend < divisor) {
                dividend = dividend * 10;
                ans += "0";
            }
            
            quotient = (dividend / divisor);
            remainder = (dividend % divisor);
                     
            ans += to_string(quotient);
            dividend = remainder;
            
            if (rem.count(remainder)) {
                int idx = rem[remainder];
                ans.insert(ans.begin() + idx, '(');
                ans += ")";
                break;
            }
            rem[remainder] = ans.size();
        }

        return ans;
    }
};