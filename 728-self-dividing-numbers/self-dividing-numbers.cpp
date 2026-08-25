class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        
        for (int num = left; num <= right; ++num) {
            if (isSelfDividing(num)) {
                result.push_back(num);
            }
        }
        
        return result;
    }

private:
    bool isSelfDividing(int num) {
        int temp = num;
        while (temp > 0) {
            int digit = temp % 10;
            // Fail if digit is 0 or if num is not divisible by digit
            if (digit == 0 || num % digit != 0) {
                return false;
            }
            temp /= 10;
        }
        return true;
    }
};