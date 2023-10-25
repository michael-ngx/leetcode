class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0;
        unordered_set<int> set(nums.begin(), nums.end());
        for (int num : nums) {
            if (set.find(num - 1) != set.end()) continue;
            // beginning of a sequence
            int count = 0;
            while (set.find(num) != set.end()) {
                count++;
                num++;
            }
            result = max(result, count);
        }
        return result;
    }
};