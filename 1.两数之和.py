#
# @lc app=leetcode.cn id=1 lang=python3
#
# [1] 两数之和
#

# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashtable = dict()
        for i in range(len(nums)):
            if target - nums[i] in hashtable:
                return hashtable[target - nums[i]], i
            hashtable[nums[i]] = i

# @lc code=end

