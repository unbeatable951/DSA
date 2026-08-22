class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int L=0;
        int maxOnes =0;
        int count =0;

        for(int r=0;r<n;r++)
        {
            if(nums[r]==0)
            {
                count++;
            }

            while(count>k)
            {
                if(nums[L]==0)
                {
                    count--;
                }
                L++;
            }

            maxOnes =max(maxOnes,r-L+1);
        }
        return maxOnes;

    }
};