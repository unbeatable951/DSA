class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

// A Small Optimization
// Our current approach works perfectly, but it always processes the entire array before making a decision.
       unordered_set<int> duplicate;
        
        for(int i = 0; i < nums.size(); i++)
         {
            if (duplicate.count(nums[i]))
            { 
                return true;
            }
            duplicate.insert(nums[i]);
        }
        return false;
    }
};