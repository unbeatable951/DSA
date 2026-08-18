class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int,int>mp;
        int n = arr.size();

        vector<int>ans;

        for(int i=0;i<n;i++)
        {
            int complement = target - arr[i];
            if(mp.find(complement)!=mp.end())
            {
                return {mp[complement]+1,i+1};
            }
            mp[arr[i]] = i;
        }

        return {};
        
    }
};