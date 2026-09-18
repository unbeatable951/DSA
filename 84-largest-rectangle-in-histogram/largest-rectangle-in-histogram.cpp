class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
{
    int n = heights.size();

    if(n == 0)
        return 0;

    vector<int> left(n);
    vector<int> right(n);

    stack<int> st;

    // Previous Smaller
    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && heights[st.top()] >= heights[i])
            st.pop();

        if(st.empty())
            left[i] = -1;
        else
            left[i] = st.top();

        st.push(i);
    }

    // Clear stack
    while(!st.empty())
        st.pop();

    // Next Smaller
    for(int i = n - 1; i >= 0; i--)
    {
        while(!st.empty() && heights[st.top()] >= heights[i])
            st.pop();

        if(st.empty())
            right[i] = n;
        else
            right[i] = st.top();

        st.push(i);
    }

    long long maxarea = 0;

    // Calculate area
    for(int i = 0; i < n; i++)
    {
        int width = right[i] - left[i] - 1;

        long long area = (long long)heights[i] * width;

        maxarea = max(maxarea, area);
    }

    return maxarea;
}
};