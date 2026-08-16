class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int min_val = *std::min_element(nums.begin(), nums.end());
        int max_val = *std::max_element(nums.begin(), nums.end());
        
        return std::max(0, max_val - min_val - 2 * k);

    }
};