# Problem: https://leetcode.com/problems/two-sum

# Time Complexity: O(n)
# Space Complexity: O(n)
# where n is the length of nums
class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        myDict = {}

        for i, val in enumerate(nums):
            counterVal = target - val

            if counterVal in myDict:
                return [myDict[counterVal], i]

            myDict[val] = i

        return []
