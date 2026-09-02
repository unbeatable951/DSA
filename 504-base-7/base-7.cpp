class Solution {
public:
    string convertToBase7(int num) {

        // Special case
        if (num == 0)
            return "0";

        string ans = "";

        // Handle negative number
        bool negative = num < 0;

        // Convert to positive
        long long n = abs((long long)num);

        // Repeated division by 7
        while (n > 0) {
            int remainder = n % 7;

            ans += char('0' + remainder);

            n /= 7;
        }

        // Digits were generated backwards
        reverse(ans.begin(), ans.end());

        // Add negative sign
        if (negative)
            ans = "-" + ans;

        return ans;
    }
};