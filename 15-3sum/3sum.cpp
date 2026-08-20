class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // Step 1: Sort the array to use two-pointer technique
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            // Optimization: If the smallest number is > 0, sum can't be 0
            if (nums[i] > 0) break;

            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    left++; // Need a larger value
                }
                 else if (sum > 0)
                {
                    right--; // Need a smaller value
                }
                 else 
                {
                    // Found a triplet
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for the second and third elements
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    // Move pointers after finding a valid triplet
                    left++;
                    right--;
                }
            }
        }
        return result;
    
    }
};