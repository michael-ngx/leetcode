class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, best = nums[0];
        for (int num : nums) {
            sum += num;
            best = max(best, sum);
            if (sum < 0) sum = 0;
        }
        return best;
    }
};