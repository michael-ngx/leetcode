class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        int result = 1, count = 1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] + 1 == nums[i + 1]) {
                count++;
                result = max(result, count);
            }
            else if (nums[i] != nums[i + 1]) {
                result = max(result, count);
                count = 1;
            }
        }
        return result;
    }
};