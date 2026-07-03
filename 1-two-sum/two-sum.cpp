class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>index;
        int sum=0;
        for(int i=0;i<=n-2;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                sum= nums[i]+nums[j];
                if(target==sum)
                {
                    index.push_back(i);
                    index.push_back(j);
                    return index;
                }
            }
        }
        return index;
    }
};