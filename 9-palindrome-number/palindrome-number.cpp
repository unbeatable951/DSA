class Solution {
public:
    bool isPalindrome(int x) {
        // Step 1: negative numbers are not palindrome
        if (x < 0) return false;

        // Step 2: numbers ending with 0 (except 0) are not palindrome
        if (x % 10 == 0 && x != 0) return false;

        int reversed = 0;

        // Step 3: reverse half of the number
        while (x > reversed) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x = x / 10;
        }

        // Step 4: check for even or odd length
        return (x == reversed || x == reversed / 10);
    }
};
