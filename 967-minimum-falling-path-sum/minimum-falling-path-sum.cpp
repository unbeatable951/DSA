class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();

    vector<vector<int>> dp(n, vector<int>(n));

    // First row: we can start anywhere
    for(int j = 0; j < n; j++) {
        dp[0][j] = matrix[0][j];
    }

    // Fill remaining rows
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n; j++) {

            int up = dp[i-1][j];

            int leftDiagonal = INT_MAX;
            if(j > 0) {
                leftDiagonal = dp[i-1][j-1];
            }

            int rightDiagonal = INT_MAX;
            if(j < n-1) {
                rightDiagonal = dp[i-1][j+1];
            }

            dp[i][j] = matrix[i][j] +
                       min(up, min(leftDiagonal, rightDiagonal));
        }
    }

    // Answer = minimum value in last row
    int ans = INT_MAX;

    for(int j = 0; j < n; j++) {
        ans = min(ans, dp[n-1][j]);
    }

    return ans;
}
};