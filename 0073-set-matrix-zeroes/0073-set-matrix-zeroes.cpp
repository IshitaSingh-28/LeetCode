#include <vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }

        int m = matrix.size();
        int n = matrix[0].size();

        bool zeroFirstRow = false;
        bool zeroFirstCol = false;

        // Check if the first row needs to be zeroed
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) {
                zeroFirstRow = true;
                break;
            }
        }

        // Check if the first column needs to be zeroed
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                zeroFirstCol = true;
                break;
            }
        }

        // Use the first row and column to mark zeroes for other cells
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set the zeroes for cells based on the markers
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero the first row if needed
        if (zeroFirstRow) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }

        // Zero the first column if needed
        if (zeroFirstCol) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
