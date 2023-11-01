class Solution {
public:
    int jump(vector<int>& nums) {
        int last = nums.size() - 1;
        nums[last] = 0;
        for (int i = last - 1; i >= 0; i--) {
            int minn = nums[i + 1];
            int end = min(last, i + nums[i]);
            for (int j = i + 2; j <= end; j++) {
                minn = min(minn, nums[j]);
            }
            nums[i] = minn + 1;
        }
        return nums[0];
    }
};