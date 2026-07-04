class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int leftsum = 0;
        int rightsum = 0;
        int totalsum =0;
        int curr=0;
        for(int i=0;i<n;i++)
        {
            totalsum+=nums[i];
        }
        for(int i=0;i<n;i++)
        {
            leftsum +=curr;
            curr = nums[i];
            rightsum = totalsum - leftsum - curr;
            if(leftsum == rightsum)
            {
                return i;
            }
        }
        return -1;       
    }
};