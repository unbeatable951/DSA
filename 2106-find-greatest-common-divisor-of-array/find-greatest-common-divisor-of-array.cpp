class Solution {
public:

 int gcd(int m,int n)
 {
    if(m==0)
    {
        return n;
    }
    else
    {
        return gcd(n%m,m);
    }
 }
    int findGCD(vector<int>& nums) 
    {
        int maxi=*max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());

        return gcd(maxi,mini);
    }
};