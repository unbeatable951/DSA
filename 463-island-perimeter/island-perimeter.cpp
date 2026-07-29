class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        int perimeter = 0;

        // Traverse every cell
        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                // Process only land cells
                if (grid[i][j] == 1) {

                    // Initially every land contributes 4 sides
                    perimeter += 4;

                    // Check Upper Neighbor
                    if (i > 0 && grid[i - 1][j] == 1)
                        perimeter--;

                    // Check Lower Neighbor
                    if (i < rows - 1 && grid[i + 1][j] == 1)
                        perimeter--;

                    // Check Left Neighbor
                    if (j > 0 && grid[i][j - 1] == 1)
                        perimeter--;

                    // Check Right Neighbor
                    if (j < cols - 1 && grid[i][j + 1] == 1)
                        perimeter--;
                }
            }
        }

        return perimeter;
    }
};