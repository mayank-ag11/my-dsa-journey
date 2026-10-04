# Problem: https://leetcode.com/problems/contains-duplicate

# Time Complexity: O(n)
# Space Complexity: O(n)
# where n is the length of nums
class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        # mySet = set()
        # for x in nums:
        #     if x in mySet:
        #         return True

        #     mySet.add(x)
        # return False
        return len(set(nums)) < len(nums)
