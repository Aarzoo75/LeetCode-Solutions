class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if target <= min(nums):
            return 0
        if target > max(nums):
            return len(nums)
        for i in range(1, len(nums), 1):
            if target <= nums[i]:
                return i