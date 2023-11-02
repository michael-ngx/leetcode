class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<pair<int,int>> cache;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') cache.push_back({i,j});
            }
        }
        while (!cache.empty()) {
            res++;
            vector<pair<int,int>> next;
            for (auto& p : cache) {
                int row = p.first;
                int col = p.second;

                if (col < n-1 && matrix[row][col+1] == '1' &&
                    row < m-1 && matrix[row+1][col] == '1' &&
                    matrix[row+1][col+1] == '1') {
                        next.push_back({row,col});
                } else {
                    matrix[row][col] = '0';
                }
            }
            swap(next, cache);
        }
        return res*res;
    }
};