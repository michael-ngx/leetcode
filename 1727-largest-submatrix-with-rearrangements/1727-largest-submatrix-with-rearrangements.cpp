class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for (int col = 0; col < m; col++) {
            for (int row = 1; row < n; row++) {
                if (!matrix[row][col]) continue;
                else matrix[row][col] += matrix[row-1][col];
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            sort(matrix[i].begin(), matrix[i].end());
            for (int j = 0; j < m; j++) {
                result = max(result, matrix[i][j] * (m - j));
            }
        }
        return result;
    }
};