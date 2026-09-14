class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int>mp;
        mp[0]=1;
        int count =0;
        int sum =0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int need = sum -k;

            if(mp.find(need)!=mp.end())
            {
                count+=mp[need];
            }
            mp[sum]++;
        }
        return count;
    }
};