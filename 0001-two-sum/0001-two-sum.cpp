class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] * 2 == target && map.find(nums[i]) != map.end()) {
                return {i, map[nums[i]]};
            }
            map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] * 2 != target && map.find(target - nums[i]) != map.end()) {
                return {i, map[target - nums[i]]};
            }
        }
        return {};
    }
};