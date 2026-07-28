class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        int rows = mat.size();
        int cols = mat[0].size();

        vector<int> ans;

        int row = 0;
        int col = 0;

        bool up = true;

        for (int i = 0; i < rows * cols; i++)
         {
            ans.push_back(mat[row][col]);
            if (up) {
                row--;
                col++;
                if (col == cols) {
                    row += 2;
                    col--;
                    up = false;
                }
                else if (row < 0) {
                    row = 0;
                    up = false;
                }
            }
            else {
                row++;
                col--;

                if (row == rows) {
                    row--;
                    col += 2;
                    up = true;
                }
                else if (col < 0) {
                    col = 0;
                    up = true;
                }
            }
        }
        return ans;
    }
};