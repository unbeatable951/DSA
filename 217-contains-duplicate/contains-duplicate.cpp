class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n= nums.size();
        unordered_set<int>duplicate;
        for(int i=0;i<n;i++)
        {
            duplicate.insert(nums[i]);
        }
        return duplicate.size()!= n ? true:false;
    }
};