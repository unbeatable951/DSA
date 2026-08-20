class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n= nums.size()-1;

        int i=0;
        int j=0;
        int k=n;

        while(j<=k)
        {
            if(nums[j]==1)
            {
                j++;
            }
            else if(nums[j]==2)
            {
                swap(nums[j],nums[k]);
                k--;
            }
            else
            {
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
        }
    }
};