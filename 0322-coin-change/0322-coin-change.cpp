class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int minn = INT_MAX;
            for (int coin : coins) {
                if (i < coin || dp[i - coin] == INT_MAX) continue;
                minn = min(minn, 1 + dp[i - coin]);
            }
            dp[i] = minn;
        }
        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};