class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        m = {}
        for i in range(len(nums)):
            num = nums[i]
            if (target - num in m):
                return [i, m[target-num]]
            m[num] = i
        return []