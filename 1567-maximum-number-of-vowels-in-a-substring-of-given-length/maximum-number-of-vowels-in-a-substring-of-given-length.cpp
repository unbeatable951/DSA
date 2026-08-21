class Solution {
public:

    bool isVowel(char ch)
    {
        if(ch =='a' || ch =='e' || ch =='i' || ch =='o'||ch=='u')
        {
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int n = s.size();

        int count =0;
        string ans = "";

        for(int i=0;i<k;i++)
        {
            if(isVowel(s[i]))
            {
                count++;
            }
        }
         int maxCount=count;

        if(maxCount==k)
        {
            return k;
        }
        for(int i=k;i<n;i++)
        {
            if(isVowel(s[i]))
            {
                count++;
            }
            if(isVowel(s[i-k]))
            {
                count--;
            }
            maxCount=max(count,maxCount);

            if(maxCount == k)
            {
                return k;
            }
        }
        return maxCount;  
    }
};