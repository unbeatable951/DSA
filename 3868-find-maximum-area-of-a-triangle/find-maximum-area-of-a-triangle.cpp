class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        int min_x = INT_MAX, max_x = INT_MIN;
        int min_y = INT_MAX, max_y = INT_MIN;

        unordered_map<int, pair<int, int>> y_to_x;
        unordered_map<int, pair<int, int>> x_to_y;

        for (const auto& p : coords) {
            int x = p[0], y = p[1];
            min_x = min(min_x, x);
            max_x = max(max_x, x);
            min_y = min(min_y, y);
            max_y = max(max_y, y);

            if (y_to_x.find(y) == y_to_x.end()) {
                y_to_x[y] = {x, x};
            } else {
                y_to_x[y].first = min(y_to_x[y].first, x);
                y_to_x[y].second = max(y_to_x[y].second, x);
            }

            if (x_to_y.find(x) == x_to_y.end()) {
                x_to_y[x] = {y, y};
            } else {
                x_to_y[x].first = min(x_to_y[x].first, y);
                x_to_y[x].second = max(x_to_y[x].second, y);
            }
        }

        long long max_2a = -1;

        // Check horizontal bases
        for (const auto& [y, range] : y_to_x) {
            if (range.first < range.second) {
                long long base = range.second - range.first;
                long long height = max(abs(y - min_y), abs(max_y - y));
                if (height > 0) {
                    max_2a = max(max_2a, base * height);
                }
            }
        }

        // Check vertical bases
        for (const auto& [x, range] : x_to_y) {
            if (range.first < range.second) {
                long long base = range.second - range.first;
                long long height = max(abs(x - min_x), abs(max_x - x));
                if (height > 0) {
                    max_2a = max(max_2a, base * height);
                }
            }
        }

        return max_2a;
        
    }
};