class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int k = p.length();

        if(k>n)
        {
            return {};
        }

        vector<int>pfreq(26,0);
        vector<int>sfreq(26,0);
        vector<int>result;

        for(int i=0;i<k;i++)
        {
            pfreq[p[i]-'a']++;
            sfreq[s[i]-'a']++;
        }

        if(pfreq == sfreq)
        {
            result.push_back(0);
        }

        for(int i=k;i<n;i++)
        {
            sfreq[s[i]-'a']++;
            sfreq[s[i-k]-'a']--;

            if(sfreq==pfreq)
            {
                result.push_back(i-k+1);
            }
        }

        return result;    
    }
};