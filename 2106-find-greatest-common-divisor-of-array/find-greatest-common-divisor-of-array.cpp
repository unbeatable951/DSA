class Solution {
public:
    // Function to find GCD using Euclidean Algorithm
    int gcd(int a, int b)
    {
        while(b != 0)
        {
            int remainder = a % b;
            a = b;
            b = remainder;
        }

        return a;
    }

    int findGCD(vector<int>& nums)
    {
        // Step 1: Assume first element is both minimum and maximum
        int mini = nums[0];
        int maxi = nums[0];

        // Step 2: Traverse the array to find minimum and maximum
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < mini)
            {
                mini = nums[i];
            }

            if(nums[i] > maxi)
            {
                maxi = nums[i];
            }
        }

        // Step 3: Return GCD of minimum and maximum
        return gcd(mini, maxi);
    }
};