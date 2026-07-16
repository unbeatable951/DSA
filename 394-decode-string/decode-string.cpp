class Solution {
public:
    string decodeString(string s) {

        stack<int> numStack;
        stack<string> strStack;

        string currentString="";
        int currentNumber=0;

        for(char ch:s)
        {
            if(isdigit(ch))
            {
                currentNumber=currentNumber*10+(ch-'0');
            }
            else if(ch=='[')
            {
                numStack.push(currentNumber);
                strStack.push(currentString);

                currentNumber=0;
                currentString="";
            }
            else if(ch==']')
            {
                int repeat=numStack.top();
                numStack.pop();

                string prev=strStack.top();
                strStack.pop();
                while(repeat--)
                {
                    prev+=currentString;
                }

                currentString=prev;
            }
            else
            {
                currentString+=ch;
            }
        }
        return currentString;
    }
};