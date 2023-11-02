class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            res = max(res, dp[i][n-1] = matrix[i][n-1] - '0');
        }
        for (int i = 0; i < n; i++) {
            res = max(res, dp[m-1][i] = matrix[m-1][i] - '0');
        }

        for (int i = m-2; i >= 0; i--) {
            for (int j = n-2; j >= 0; j--) {
                if (matrix[i][j] == '0') continue;
                int val = 1 + min(min(dp[i][j+1], 
                                    dp[i+1][j]),
                                    dp[i+1][j+1]);
                res = max(res, val);
                dp[i][j] = val;
            }
        }
        return res*res;
    }
};