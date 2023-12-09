class Solution {
public:
    /* Matrix of s1, s2
     dp[i][j] denote whether s1[0...i] and s2[0...j] can interleave and form s3[0...i+j]
     Optimal subproblem: Can interleave <=> (next char from s1 == next char s3) && dp[i-1][j] 
                                         OR (next char from s2 == next char s3) && dp[i][j-1]
    */
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), h = s3.size();
        if (h != m + n) return false;
        bool cache[m + 1][n + 1];
        cache[0][0] = true;
        for (int i = 1; i <= m; i++) {
            cache[i][0] = cache[i-1][0] && (s1[i-1] == s3[i-1]);
        }
        for (int i = 1; i <= n; i++) {
            cache[0][i] = cache[0][i-1] && (s2[i-1] == s3[i-1]);
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cache[i][j] = (s1[i-1] == s3[i+j-1] && cache[i-1][j]) || (s2[j-1] == s3[i+j-1] && cache[i][j-1]);
            }
        }
        return cache[m][n];
    }
};