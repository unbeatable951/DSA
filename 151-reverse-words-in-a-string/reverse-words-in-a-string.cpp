class Solution {
public:
    string reverseWords(string s) {
        //Clean Up the spaces 
        int n= s.length();
        int read = 0;
        int write =0;

        while(read<n)
        {
            while(read<n && s[read] ==' ')
            {
                read++;
            }
            
            if(read>=n)
            {
                break;
            }
            if(write>0)
            {
                s[write++]=' ';
            }
            while(read <n && s[read] !=' ')
            {
                s[write++] = s[read++];
            }
        }

        s.resize(write);
        n = s.length();

        reverse(s.begin(),s.end());

        int start =0;
        for(int end =0;end<=n;end++)
        {
            if(end== n || s[end] ==' ')
            {
                reverse(s.begin() + start, s.begin()+end);
                start = end+1;
            }
        }
        return s;
    }
};